#include "dec/decoder_phy.h"
#include "dec/music_api.h"
#include "music_prompt.h"
#include "play_sel/play_sel.h"
#include "dac.h"
#include "music.h"

#if SUPPORT_ALL_VOICE
bool prompt_played,music_prompt_stopped;
#else
bool music_prompt_break;
#endif
u32 prompt_op_msg = 0;    //prompt related operation


#ifdef SUPPORT_VOICE_ONOFF
bool bVoiceOnoff;
#endif




/*----------------------------------------------------------------------------*/
/**@brief  Music语音播放函数
   @param  file_name：语音文件号
           m_op_api：解码接口
           msg : prompt related operation
   @return NULL
   @note   u32 music_prompt_play(MUSIC_OP_API *m_op_api,void * file_name ,u32 msg)
*/
/*----------------------------------------------------------------------------*/
u32 music_prompt_play(MUSIC_OP_API *m_op_api,void *file_name,u32 msg)
{
#if  SUPPORT_ALL_VOICE
    if(music_prompt_stopped)
    {
        puts("music_prompt_stopped ok\n");
        if(!prompt_played)
            music_prompt_stopped = 0;
    }
    else
    {
        puts("music_prompt_stopped err\n");
        return 1;
    }
#else

    if(play_sel_busy())
    {
        /*提示音打断*/
        music_prompt_break = 1;
        play_sel_stop();
    }

#endif

#if  SUPPORT_ALL_VOICE

    switch(msg)
    {

	 #ifdef SUPPORT_SCG_VOICE
	 	
		case MSG_MUSIC_PAUSE:
	 		prompt_op_msg = msg;
	 		m_op_api->dop_api->dec_api.save_brk = 1;
	 		music_stop_decoder(m_op_api);
	 		if(bVoiceOnoff==1)				
	 		{			 			 
	 			tone_play_by_name("MusicTask",1, BPF_PAUSE_EN_MP3);
	 		}
		break;

		case MSG_MUSIC_PLAY:
	 		prompt_op_msg = msg;
	 		m_op_api->dop_api->dec_api.save_brk = 1;
	 		music_stop_decoder(m_op_api);
	 		if(bVoiceOnoff==1)				
	 		{			 			 
	 			tone_play_by_name("MusicTask",1, BPF_PLAY_EN_MP3);
	 		}
		break;

		case MSG_MUSIC_NEXT_FILE:	
	 		prompt_op_msg = msg;
	 		m_op_api->dop_api->dec_api.save_brk = 0;
	 		music_stop_decoder(m_op_api);
	 		if(bVoiceOnoff)				
	 		{			 			 
	 			tone_play_by_name("MusicTask",1, BPF_NEXT_EN_MP3);
	 		}
		break;

		case MSG_MUSIC_PREV_FILE:
	 		prompt_op_msg = msg;
	 		m_op_api->dop_api->dec_api.save_brk = 0;
	 		music_stop_decoder(m_op_api);
	 		if(bVoiceOnoff)				
	 		{			 			 
	 			tone_play_by_name("MusicTask",1, BPF_PREV_EN_MP3);
	 		}
		break;    

		case MSG_MUSIC_RPT:
	 		prompt_op_msg = msg;
	 		m_op_api->dop_api->dec_api.save_brk = 1;
	 		music_stop_decoder(m_op_api);
	 
	 		if(play_mode == REPEAT_ALL)
	 		{            	
	 	 		if(bVoiceOnoff)				
	 	 		{			 			 
	 	 			tone_play_by_name("MusicTask",1, BPF_REP_ALL_EN_MP3);
	 	 		}
	 		} 
	 		else
	 		{
	 	 		if(bVoiceOnoff)				
	 	 		{			 			 
	 	 			tone_play_by_name("MusicTask",1, BPF_REP_ONE_EN_MP3);
	 	 		}
	 		}
		break;
	 
	 #else
	 	
	         case MSG_MUSIC_PAUSE:
	 
	 		prompt_op_msg = msg;
	             m_op_api->dop_api->dec_api.save_brk = 1;
	             music_stop_decoder(m_op_api);
	 	 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
	 	 	if(IsVoiceEnable==2)				
	 	 	{			 			 
	 	 		tone_play_by_name("MusicTask",1, BPF_PAUSE_EN_MP3);
	 	 	}
	 	 	else				
	 	 #endif		 						            					 		 			 		
	 			
	             tone_play_by_name("MusicTask",1, BPF_PAUSE_MP3);
	             break;
	 
	         case MSG_MUSIC_PLAY:
	 
	 		prompt_op_msg = msg;
	             m_op_api->dop_api->dec_api.save_brk = 1;
	             music_stop_decoder(m_op_api);
	 	 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
	 	 	if(IsVoiceEnable==2)				
	 	 	{			 			 
	 	 		tone_play_by_name("MusicTask",1, BPF_PLAY_EN_MP3);
	 	 	}
	 	 	else				
	 	 #endif		 						            					 		 			 					
	             tone_play_by_name("MusicTask",1, BPF_PLAY_MP3);
	             break;
	             
	         case MSG_MUSIC_NEXT_FILE:	
	 
	 		prompt_op_msg = msg;
	             m_op_api->dop_api->dec_api.save_brk = 0;
	             music_stop_decoder(m_op_api);
	  	 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
	 	 	if(IsVoiceEnable==2)				
	 	 	{			 			 
	 	 		tone_play_by_name("MusicTask",1, BPF_NEXT_EN_MP3);
	 	 	}
	 	 	else				
	 	 #endif		 						            					 		 			 					
	            tone_play_by_name("MusicTask",1, BPF_NEXT_MP3);
	 			
	 
	             break;
	 
	         case MSG_MUSIC_PREV_FILE:
	 
	 		prompt_op_msg = msg;
	             m_op_api->dop_api->dec_api.save_brk = 0;
	             music_stop_decoder(m_op_api);
	  	 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
	 	 	if(IsVoiceEnable==2)				
	 	 	{			 			 
	 	 		tone_play_by_name("MusicTask",1, BPF_PREV_EN_MP3);
	 	 	}
	 	 	else				
	 	 #endif		 						            					 		 			 					
	             tone_play_by_name("MusicTask",1, BPF_PREV_MP3);
	 
	 			
	 	   break;    
	 
	 		case MSG_MUSIC_RPT:
	 
	 		prompt_op_msg = msg;
	             m_op_api->dop_api->dec_api.save_brk = 1;
	             music_stop_decoder(m_op_api);
	             
	 	if(play_mode == REPEAT_ALL)
	             {            	
	 	 	 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
	 		 	if(IsVoiceEnable==2)				
	 		 	{			 			 
	 		 		tone_play_by_name("MusicTask",1, BPF_REP_ALL_EN_MP3);
	 		 	}
	 		 	else				
	 		 #endif		 						            					 		 			 					
	 			tone_play_by_name("MusicTask",1, BPF_REP_ALL_MP3);
	             } 
	             else
	             {
	 	 	 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
	 		 	if(IsVoiceEnable==2)				
	 		 	{			 			 
	 		 		tone_play_by_name("MusicTask",1, BPF_REP_ONE_EN_MP3);
	 		 	}
	 		 	else				
	 		 #endif		 						            					 		 			 					
	 			tone_play_by_name("MusicTask",1, BPF_REP_ONE_MP3);
	             }
	             break;
	 
	 #endif


			
#if SUPPORT_TY_VOICE==0
		#if SUPPORT_EQ_VOICE
		#ifdef SUPPORT_SCG_VOICE


		#else
		case MSG_MUSIC_EQ:	

		prompt_op_msg = msg;
            	m_op_api->dop_api->dec_api.save_brk = 1;
            	music_stop_decoder(m_op_api);

	 	 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
		 	if(IsVoiceEnable==2)				
		 	{
				if(eq_mode == 0)	
			            {
			            	tone_play_by_name("MusicTask",1, BPF_NORMAL_EN_MP3);
			            }
			            else if(eq_mode == 1)
			            {
			            	tone_play_by_name("MusicTask",1, BPF_ROCK_EN_MP3);
			            }
			            else if(eq_mode == 2)
			            {
			            
			            	tone_play_by_name("MusicTask",1, BPF_POP_EN_MP3);
			            }
			            else if(eq_mode == 3)
			            {
			            
			            	tone_play_by_name("MusicTask",1, BPF_CLASS_EN_MP3);
			            }
			            else if(eq_mode == 4)
			            {
			            
			            	tone_play_by_name("MusicTask",1, BPF_JAZZ_EN_MP3);
			            }
			            else if(eq_mode == 5)
			            {
			            
			           		 tone_play_by_name("MusicTask",1, BPF_SOFT_EN_MP3);
			            }
		 	}
		 	else				
		 #endif		 						            					 		 			 					
		 	{
	 				if(eq_mode == 0)	
	 			            {
	 			            	tone_play_by_name("MusicTask",1, BPF_NORMAL_MP3);
	 			            }
	 			            else if(eq_mode == 1)
	 			            {
	 			            	tone_play_by_name("MusicTask",1, BPF_ROCK_MP3);
	 			            }
	 			            else if(eq_mode == 2)
	 			            {
	 			            
	 			            	tone_play_by_name("MusicTask",1, BPF_POP_MP3);
	 			            }
	 			            else if(eq_mode == 3)
	 			            {
	 			            
	 			            	tone_play_by_name("MusicTask",1, BPF_CLASS_MP3);
	 			            }
	 			            else if(eq_mode == 4)
	 			            {
	 			            
	 			            	tone_play_by_name("MusicTask",1, BPF_JAZZ_MP3);
	 			            }
	 			            else if(eq_mode == 5)
	 			            {
	 			            
	 			           		 tone_play_by_name("MusicTask",1, BPF_SOFT_MP3);
	 			            }
						
		 	}
	            break;
		#endif
		#endif
		
 	 #if SUPPORT_VOICE_NUMBER
	#ifdef SUPPORT_SCG_VOICE


	#else

	 
		case MSG_VOICE_NUMBER:	

		prompt_op_msg = msg;
            	m_op_api->dop_api->dec_api.save_brk = 1;
            	music_stop_decoder(m_op_api);
				
		 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE			 
			 if(IsVoiceEnable==2)
			 {
			 		if(bVoiceNumber == 0)	
			 	            {
			 	            	tone_play_by_name("MusicTask",1, BPF_0_EN_MP3);
			 	            }
			 	            else if(bVoiceNumber == 1)
			 	            {
			 	            	tone_play_by_name("MusicTask",1, BPF_1_EN_MP3);
			 	            }
			 	            else if(bVoiceNumber == 2)
			 	            {
			 	            
			 	            	tone_play_by_name("MusicTask",1, BPF_2_EN_MP3);
			 	            }
			 	            else if(bVoiceNumber == 3)
			 	            {
			 	            
			 	            	tone_play_by_name("MusicTask",1, BPF_3_EN_MP3);
			 	            }
			 	            else if(bVoiceNumber == 4)
			 	            {
			 	            
			 	            	tone_play_by_name("MusicTask",1, BPF_4_EN_MP3);
			 	            }
			 	            else if(bVoiceNumber == 5)
			 	            {
			 	            
			 	           		 tone_play_by_name("MusicTask",1, BPF_5_EN_MP3);
			 	            }
			 	            else if(bVoiceNumber == 6)
			 	            {
			 	            	tone_play_by_name("MusicTask",1, BPF_6_EN_MP3);
			 	            }
			 	            else if(bVoiceNumber == 7)
			 	            {
			 	            
			 	            	tone_play_by_name("MusicTask",1, BPF_7_EN_MP3);
			 	            }
			 	            else if(bVoiceNumber == 8)
			 	            {
			 	            
			 	            	tone_play_by_name("MusicTask",1, BPF_8_EN_MP3);
			 	            }
			 	            else if(bVoiceNumber == 9)
			 	            {
			 	            
			 	            	tone_play_by_name("MusicTask",1, BPF_9_EN_MP3);
			 	            }
			 }			 
			 else
		 #endif
			 {
			 #ifdef SUPPORT_SCG_VOICE


			 #else
			 		if(bVoiceNumber == 0)	
			 	            {
			 	            	tone_play_by_name("MusicTask",1, BPF_0_MP3);
			 	            }
			 	            else if(bVoiceNumber == 1)
			 	            {
			 	            	tone_play_by_name("MusicTask",1, BPF_1_MP3);
			 	            }
			 	            else if(bVoiceNumber == 2)
			 	            {
			 	            
			 	            	tone_play_by_name("MusicTask",1, BPF_2_MP3);
			 	            }
			 	            else if(bVoiceNumber == 3)
			 	            {
			 	            
			 	            	tone_play_by_name("MusicTask",1, BPF_3_MP3);
			 	            }
			 	            else if(bVoiceNumber == 4)
			 	            {
			 	            
			 	            	tone_play_by_name("MusicTask",1, BPF_4_MP3);
			 	            }
			 	            else if(bVoiceNumber == 5)
			 	            {
			 	            
			 	           		 tone_play_by_name("MusicTask",1, BPF_5_MP3);
			 	            }
			 	            else if(bVoiceNumber == 6)
			 	            {
			 	            	tone_play_by_name("MusicTask",1, BPF_6_MP3);
			 	            }
			 	            else if(bVoiceNumber == 7)
			 	            {
			 	            
			 	            	tone_play_by_name("MusicTask",1, BPF_7_MP3);
			 	            }
			 	            else if(bVoiceNumber == 8)
			 	            {
			 	            
			 	            	tone_play_by_name("MusicTask",1, BPF_8_MP3);
			 	            }
			 	            else if(bVoiceNumber == 9)
			 	            {
			 	            
			 	            	tone_play_by_name("MusicTask",1, BPF_9_MP3);
			 	            }


			 #endif

			 }	
								
	            break;
		#endif	
		#endif	
		
	 #ifdef SUPPORT_MUTE_VOICE
	 
		case MSG_VOICE_MUTE:

			prompt_op_msg = MSG_PROMPT_PLAY;
	            m_op_api->dop_api->dec_api.save_brk = 1;
	            music_stop_decoder(m_op_api);

		 	 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
		 		if(IsVoiceEnable==2)				
		 		{
		           		 tone_play_by_name("MusicTask",1, BPF_MUTE_EN_MP3);
				}
		 		else				
		  	#endif	
				if(IsVoiceEnable)
			    	{
			            tone_play_by_name("MusicTask",1, BPF_MUTE_MP3);
			    	}			
            break;

			
	    case MSG_VOICE_MUTE_OFF:

			prompt_op_msg = MSG_PROMPT_PLAY;
	            m_op_api->dop_api->dec_api.save_brk = 1;
	            music_stop_decoder(m_op_api);

		 	 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
		 		if(IsVoiceEnable==2)				
		 		{
		            tone_play_by_name("MusicTask",1, BPF_MUTE_OFF_EN_MP3);
				}
		 		else				
		  	#endif	
			if(IsVoiceEnable)
		    	{
		            tone_play_by_name("MusicTask",1, BPF_MUTE_OFF_MP3);
		    	}	
			
	    	break;
			
	#endif



		 #ifdef SUPPORT_SCG_VOICE
		 
		 
		 	case MSG_VOICE_VOLUME_PLUS:
		 		prompt_op_msg = msg;
		 		m_op_api->dop_api->dec_api.save_brk = 1;
		 		music_stop_decoder(m_op_api);
		 
		 		if(bVoiceOnoff)				
	 		 	{
	 		 		if(dac_ctl.sys_vol_l ==30)	
	 		 			tone_play_by_name("MusicTask",1, BPF_VL_MAX_MP3);
	 		 		else		
	 		 			tone_play_by_name("MusicTask",1, BPF_VL_INC_MP3);
	 		 	}		 	
		 	break;
		 
		 
		 	case MSG_VOICE_VOLUME_MINUS:
		 		prompt_op_msg = msg;
		 		m_op_api->dop_api->dec_api.save_brk = 1;
		 		music_stop_decoder(m_op_api);            
		 		if(bVoiceOnoff)				
	 		 	{
	 		 		tone_play_by_name("MusicTask",1, BPF_VL_DEC_MP3);
	 		 	}		 	
		 	break;


#else

        case MSG_VOICE_VOLUME_PLUS:

		prompt_op_msg = msg;
            m_op_api->dop_api->dec_api.save_brk = 1;
            music_stop_decoder(m_op_api);

	 	 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
		 	if(IsVoiceEnable==2)				
		 	{
				if(dac_ctl.sys_vol_l ==30)	
					tone_play_by_name("MusicTask",1, BPF_VL_MAX_EN_MP3);
				else		
					tone_play_by_name("MusicTask",1, BPF_VL_INC_EN_MP3);
		 	}		 	
		 	else				
		 #endif	

			#if SUPPORT_VOL_VOICE			
		 	{
				if(dac_ctl.sys_vol_l ==30)	
					tone_play_by_name("MusicTask",1, BPF_VL_MAX_MP3);
				else		
					tone_play_by_name("MusicTask",1, BPF_VL_INC_MP3);
		 	}

		 #endif
          break;


         case MSG_VOICE_VOLUME_MINUS:

		prompt_op_msg = msg;
            m_op_api->dop_api->dec_api.save_brk = 1;
            music_stop_decoder(m_op_api);            
	 	 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
		 	if(IsVoiceEnable==2)				
		 	{
          			  tone_play_by_name("MusicTask",1, BPF_VL_DEC_EN_MP3);
		 	}		 	
		 	else				
		 #endif	

		 #if SUPPORT_VOL_VOICE			
		 	tone_play_by_name("MusicTask",1, BPF_VL_DEC_MP3);
		 #endif
           break;

		 
		 #endif





	


			
	#ifdef SUPPORT_VOICE_ONOFF_KEY_SINGLE_KEY
	
		case MSG_MUSIC_VOICE_SWITCH:	

			prompt_op_msg = msg;

			m_op_api->dop_api->dec_api.save_brk = 1;
			music_stop_decoder(m_op_api);		            
			if(IsVoiceEnable)
			{
			 	if(bStoreVoiceVal==2)				
			 	{
					tone_play_by_name("MusicTask",1, BPF_VOICE_ON_EN_MP3);
			 	}		 	
			 	else				
				{
					tone_play_by_name("MusicTask",1, BPF_VOICE_ON_MP3);
				}
			}
			else
			{
			 	if(bStoreVoiceVal==2)				
			 	{
					tone_play_by_name("MusicTask",1, BPF_VOICE_OFF_EN_MP3);
			 	}		 	
			 	else				
				{
					tone_play_by_name("MusicTask",1, BPF_VOICE_OFF_MP3);
				}
			}			
		 
			break;

		case MSG_MUSIC_VOICE_CHANGE:	

			prompt_op_msg = msg;

			m_op_api->dop_api->dec_api.save_brk = 1;
			music_stop_decoder(m_op_api);		            

			 	if(IsVoiceEnable==2)				
			 	{
					tone_play_by_name("MusicTask",1, BPF_VOICE_EN_MP3);
			 	}		 	
			 	else				
				{
					tone_play_by_name("MusicTask",1, BPF_VOICE_CH_MP3);
				}
		 
			break;
			
	#else
	
		case MSG_MUSIC_VOICE_SWITCH:	

		prompt_op_msg = msg;

		m_op_api->dop_api->dec_api.save_brk = 1;
		music_stop_decoder(m_op_api);		            

	 	 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
		 	if(IsVoiceEnable==2)				
		 	{
			tone_play_by_name("MusicTask",1, BPF_VOICE_ON_EN_MP3);
		 	}		 	
		 	else				
		 #endif	
		 #ifdef SUPPORT_SCG_VOICE



		#else
			if(IsVoiceEnable)
			{
				tone_play_by_name("MusicTask",1, BPF_VOICE_ON_MP3);
			}
			else
			{
				tone_play_by_name("MusicTask",1, BPF_VOICE_OFF_MP3);
			}		
		
		 #endif
 
		break;
	 #endif
#else

 	#ifdef SUPPORT_VOICE_MODE_KEY
	
		case MSG_MUSIC_VOICE_SWITCH:	

		prompt_op_msg = msg;

		m_op_api->dop_api->dec_api.save_brk = 1;
		music_stop_decoder(m_op_api);		            

			if(IsVoiceEnable)
			{
				tone_play_by_name("MusicTask",1, BPF_VOICE_ON_MP3);
			}
			else
			{
				tone_play_by_name("MusicTask",1, BPF_VOICE_OFF_MP3);
			}		 
		break;
	#endif

#endif
#ifdef SUPPORT_SCG_VOICE
	 #if SUPPORT_EQ_VOICE
	 
	 	case MSG_MUSIC_EQ:	
	 
	 	prompt_op_msg = msg;
	 	m_op_api->dop_api->dec_api.save_brk = 1;
	 	music_stop_decoder(m_op_api);
	 	if(bVoiceOnoff)				
	 	{
	 	 	if(eq_mode == 0)	
	 	 	{
	 	 		tone_play_by_name("MusicTask",1, BPF_NORMAL_EN_MP3);
	 	 	}
	 	 	else if(eq_mode == 1)
	 	 	{
	 	 		tone_play_by_name("MusicTask",1, BPF_ROCK_EN_MP3);
	 	 	}
	 	 	else if(eq_mode == 2)
	 	 	{
	 	 		tone_play_by_name("MusicTask",1, BPF_POP_EN_MP3);
	 	 	}
	 	 	else if(eq_mode == 3)
	 	 	{
	 	 		tone_play_by_name("MusicTask",1, BPF_CLASS_EN_MP3);
	 	 	}
	 	 	else if(eq_mode == 4)
	 	 	{
	 	 		tone_play_by_name("MusicTask",1, BPF_JAZZ_EN_MP3);
	 	 	}
	 	 	else if(eq_mode == 5)
	 	 	{
	 	 		tone_play_by_name("MusicTask",1, BPF_SOFT_EN_MP3);
	 	 	}
	 	}
	 		
	 	break;
	 #endif

#if SUPPORT_VOICE_NUMBER

	case MSG_VOICE_NUMBER:	

	prompt_op_msg = msg;
	m_op_api->dop_api->dec_api.save_brk = 1;
	music_stop_decoder(m_op_api);

	if(bVoiceOnoff)
	{
	 	if(bVoiceNumber == 0)	
	 	{
	 		tone_play_by_name("MusicTask",1, BPF_0_EN_MP3);
	 	}
	 	else if(bVoiceNumber == 1)
	 	{
	 		tone_play_by_name("MusicTask",1, BPF_1_EN_MP3);
	 	}
	 	else if(bVoiceNumber == 2)
	 	{
	 		tone_play_by_name("MusicTask",1, BPF_2_EN_MP3);
	 	}
	 	else if(bVoiceNumber == 3)
	 	{
	 		tone_play_by_name("MusicTask",1, BPF_3_EN_MP3);
	 	}
	 	else if(bVoiceNumber == 4)
	 	{
	 		tone_play_by_name("MusicTask",1, BPF_4_EN_MP3);
	 	}
	 	else if(bVoiceNumber == 5)
	 	{
	 		tone_play_by_name("MusicTask",1, BPF_5_EN_MP3);
	 	}
	 	else if(bVoiceNumber == 6)
	 	{
	 		tone_play_by_name("MusicTask",1, BPF_6_EN_MP3);
	 	}
	 	else if(bVoiceNumber == 7)
	 	{
	 		tone_play_by_name("MusicTask",1, BPF_7_EN_MP3);
	 	}
	 	else if(bVoiceNumber == 8)
	 	{
	 		tone_play_by_name("MusicTask",1, BPF_8_EN_MP3);
	 	}
	 	else if(bVoiceNumber == 9)
	 	{
	 		tone_play_by_name("MusicTask",1, BPF_9_EN_MP3);
	 	}
	}			 
	break;
#endif	

#ifdef SUPPORT_MUTE_VOICE

	case MSG_VOICE_MUTE:
	 	prompt_op_msg = MSG_PROMPT_PLAY;
	 	m_op_api->dop_api->dec_api.save_brk = 1;
	 	music_stop_decoder(m_op_api);
	 
	 	if(bVoiceOnoff)				
	 	{
	 		tone_play_by_name("MusicTask",1, BPF_MUTE_EN_MP3);
	 	}	
	break;


	case MSG_VOICE_MUTE_OFF:
	 	prompt_op_msg = MSG_PROMPT_PLAY;
	 	m_op_api->dop_api->dec_api.save_brk = 1;
	 	music_stop_decoder(m_op_api);
	 
	 	if(bVoiceOnoff)				
	 	{
	 		tone_play_by_name("MusicTask",1, BPF_MUTE_OFF_EN_MP3);
	 	}
	break;

#endif


#endif

	
#ifdef SUPPORT_RECPLAY_VOICE
		case MSG_MUSIC_PLAY_REC_FILE:
		prompt_op_msg = msg;

		m_op_api->dop_api->dec_api.save_brk = 1;
		music_stop_decoder(m_op_api);		            

	 	 #ifdef SUPPORT_DOUBLE_VOICE_AND_NOTICE
		 	if(IsVoiceEnable==2)				
		 	{
			tone_play_by_name("MusicTask",1, BPF_RECPLAY_EN_MP3);
		 	}		 	
		 	else				
		 #endif	
			tone_play_by_name("MusicTask",1, BPF_RECPLAY_MP3);	 
		break;	
#endif

#ifdef SUPPORT_MIC_ONOFF_VOICE

		case MSG_VOICE_MIC:
		prompt_op_msg = msg;

		m_op_api->dop_api->dec_api.save_brk = 1;
		music_stop_decoder(m_op_api);		            

		if(mic_sw)
		{
			tone_play_by_name("MusicTask",1, BPF_MIC_ON_MP3);
		}
		else
		{
			tone_play_by_name("MusicTask",1, BPF_MIC_OFF_MP3);
		}		 

		break;
#endif

        default:
		prompt_op_msg = msg;
		m_op_api->dop_api->dec_api.save_brk = 1;//提示音结束断点播放
		music_stop_decoder(m_op_api);
		tone_play_by_name("MusicTask",1,file_name);
		return 1;        
            break;
    }
    return 1;
	
#elif defined SUPPORT_MODE_VOICE_EN_CH_ONOFF

    switch(msg)
    {
    
	#if defined SUPPORT_PP_PREV_NEXT_VOICE
	
        case MSG_MUSIC_PAUSE:
			
		prompt_op_msg = msg;
            m_op_api->dop_api->dec_api.save_brk = 1;
            music_stop_decoder(m_op_api);
	 	if(bModeVoiceSelVal==2)				
	 	{			 			 
	 		tone_play_by_name("MusicTask",1, BPF_PAUSE_EN_MP3);
	 	}
	 	else					
          		  tone_play_by_name("MusicTask",1, BPF_PAUSE_MP3);
            break;
	 
        case MSG_MUSIC_PLAY:

		prompt_op_msg = msg;
            m_op_api->dop_api->dec_api.save_brk = 1;
            music_stop_decoder(m_op_api);

	 	if(bModeVoiceSelVal==2)				
	 	{			 			 
	 		tone_play_by_name("MusicTask",1, BPF_PLAY_EN_MP3);
	 	}
	 	else					
         	  tone_play_by_name("MusicTask",1, BPF_PLAY_MP3);
            break;
            
        case MSG_MUSIC_NEXT_FILE:	

		prompt_op_msg = msg;
            m_op_api->dop_api->dec_api.save_brk = 0;
            music_stop_decoder(m_op_api);

	 	if(bModeVoiceSelVal==2)				
	 	{			 			 
	 		tone_play_by_name("MusicTask",1, BPF_NEXT_EN_MP3);
	 	}
	 	else					
          tone_play_by_name("MusicTask",1, BPF_NEXT_MP3);
			

            break;

        case MSG_MUSIC_PREV_FILE:

		prompt_op_msg = msg;
            m_op_api->dop_api->dec_api.save_brk = 0;
            music_stop_decoder(m_op_api);

	 	if(bModeVoiceSelVal==2)				
	 	{			 			 
	 		tone_play_by_name("MusicTask",1, BPF_PREV_EN_MP3);
	 	}
	 	else					
	            tone_play_by_name("MusicTask",1, BPF_PREV_MP3);
			
	 	  break;    
	 #endif		 						            					 		 			 					

   #ifdef SUPPORT_MUSIC_REPEAT_VOICE
		case MSG_MUSIC_RPT:

			prompt_op_msg = msg;
			m_op_api->dop_api->dec_api.save_brk = 1;
			music_stop_decoder(m_op_api);
	            
			if(play_mode == REPEAT_ALL)
		            {            	

				 	if(bModeVoiceSelVal==2)				
				 	{			 			 
				 		tone_play_by_name("MusicTask",1, BPF_REP_ALL_EN_MP3);
				 	}
				 	else					
					tone_play_by_name("MusicTask",1, BPF_REP_ALL_MP3);
		            } 
		            else
		            {
				 	if(bModeVoiceSelVal==2)				
				 	{			 			 
				 		tone_play_by_name("MusicTask",1, BPF_REP_ONE_EN_MP3);
				 	}
				 	else						
					tone_play_by_name("MusicTask",1, BPF_REP_ONE_MP3);
		            }
					
	            break;
	 #endif		 						            					 		 			 					
			

		   #ifdef SUPPORT_MUSIC_EQ_VOICE
		   
			case MSG_MUSIC_EQ:	

			prompt_op_msg = msg;
	            	m_op_api->dop_api->dec_api.save_brk = 1;
	            	music_stop_decoder(m_op_api);

			 	if(bModeVoiceSelVal==2)				
			 	{
					if(eq_mode == 0)	
				            {
				            	tone_play_by_name("MusicTask",1, BPF_NORMAL_EN_MP3);
				            }
				            else if(eq_mode == 1)
				            {
				            	tone_play_by_name("MusicTask",1, BPF_ROCK_EN_MP3);
				            }
				            else if(eq_mode == 2)
				            {
				            
				            	tone_play_by_name("MusicTask",1, BPF_POP_EN_MP3);
				            }
				            else if(eq_mode == 3)
				            {
				            
				            	tone_play_by_name("MusicTask",1, BPF_CLASS_EN_MP3);
				            }
				            else if(eq_mode == 4)
				            {
				            
				            	tone_play_by_name("MusicTask",1, BPF_JAZZ_EN_MP3);
				            }
				            else if(eq_mode == 5)
				            {
				            
				           		 tone_play_by_name("MusicTask",1, BPF_SOFT_EN_MP3);
				            }
			 	}
			 	else				
			 	{
					if(eq_mode == 0)	
				            {
				            	tone_play_by_name("MusicTask",1, BPF_NORMAL_MP3);
				            }
				            else if(eq_mode == 1)
				            {
				            	tone_play_by_name("MusicTask",1, BPF_ROCK_MP3);
				            }
				            else if(eq_mode == 2)
				            {
				            
				            	tone_play_by_name("MusicTask",1, BPF_POP_MP3);
				            }
				            else if(eq_mode == 3)
				            {
				            
				            	tone_play_by_name("MusicTask",1, BPF_CLASS_MP3);
				            }
				            else if(eq_mode == 4)
				            {
				            
				            	tone_play_by_name("MusicTask",1, BPF_JAZZ_MP3);
				            }
				            else if(eq_mode == 5)
				            {
				            
				           		 tone_play_by_name("MusicTask",1, BPF_SOFT_MP3);
				            }
			 	}
		            break;
			#endif		 						            					 		 			 						

        default:
		prompt_op_msg = msg;
		m_op_api->dop_api->dec_api.save_brk = 1;//提示音结束断点播放
		music_stop_decoder(m_op_api);
		tone_play_by_name("MusicTask",1,file_name);
		return 1;        
            break;
    }
    return 1;
	
#else
    prompt_op_msg = msg;
    m_op_api->dop_api->dec_api.save_brk = 1;//提示音结束断点播放
    music_stop_decoder(m_op_api);
    tone_play_by_name(MUSIC_TASK_NAME,1,file_name);
    return 1;

#endif


}

/*----------------------------------------------------------------------------*/
/**@brief  Music prompt play end
   @param
   @return res = 0:stop
   		   res = 1:play
   @note   u32 prompt_play_end()
*/
/*----------------------------------------------------------------------------*/
#define MUSIC_STOP	0   //stop after prompt play end
#define MUSIC_PLAY	1   //continue play after prompt play end
u32 prompt_play_end(void)
{
    u32 res = MUSIC_STOP;

#if  SUPPORT_ALL_VOICE
    music_prompt_stopped = 1;
#endif	
	
    switch(prompt_op_msg)
    {
    case MSG_PROMPT_PLAY:
    case MSG_LOW_POWER:
        res = MUSIC_PLAY;
        puts("prompt_play_end:MSG_LOW_POWER\n");
        break;
    case MSG_MUSIC_PLAY:
        res = MUSIC_PLAY;
        puts("prompt_play_end:MSG_MUSIC_PLAY\n");
        break;
    case MSG_MUSIC_PAUSE:
        res = MUSIC_STOP;
        puts("prompt_play_end:MSG_MUSIC_PAUSE\n");
        break;
    default:
        res = MUSIC_PLAY;
        puts("prompt_play_end:default\n");
        break;
    }
    return res;
}
