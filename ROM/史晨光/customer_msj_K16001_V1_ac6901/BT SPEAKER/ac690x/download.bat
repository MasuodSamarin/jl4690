@echo off

@echo ********************************************************************************
@echo 			SDK BR17 %4  ...			
@echo ********************************************************************************
@echo %date%

cd %~dp0

if exist %1.bin del %1.bin 
if exist %1.lst del %1.lst 

REM  echo %1
REM  echo %2
REM  echo %3
REM  echo %4

REM  %2 -disassemble %1.or32 > %1.lst 
%3 -O binary -j .text  %1.or32  %1.bin 
%3 -O binary -j .data  %1.or32  data.bin 
%3 -O binary -j .data1 %1.or32  data1.bin 
%2 -section-headers  %1.or32 

copy %1.bin/b + data.bin/b + data1.bin/b sdram.app

REM if exist %1.or32 del %1.or32
del %1.bin data.bin data1.bin

if exist uboot.boot del uboot.boot
type uboot.bin ver.bin> uboot.boot 

cd ui_resource
copy *.* ..\
cd ..


if "%4" == "MINI" (
cd tone_resource_mini
copy *.mp3 ..\
cd ..
isd_download.exe -tonorflash -dev br17 -boot 0x2000 -div6 -wait 300 -format cfg -f uboot.boot sdram.app bt_cfg.bin fast_run.bin power_off.mp3 bt.mp3 music.mp3 linein.mp3 radio.mp3 pc.mp3 wait.mp3 connect.mp3 disconnect.mp3 ring.mp3 0.mp3 1.mp3 2.mp3 3.mp3 4.mp3 5.mp3 6.mp3 7.mp3 8.mp3 9.mp3
)

if "%4" == "NORMAL" (
cd tone_resource
copy *.mp3 ..\
cd ..
isd_download.exe -tonorflash -dev br17 -boot 0x2000 -div6 -wait 300 -format cfg -f uboot.boot sdram.app bt_cfg.bin fast_run.bin power_off.mp3 bt.mp3 music.mp3 record.mp3 linein.mp3 radio.mp3 pc.mp3 rec.mp3 recplay.mp3 wait.mp3 connect.mp3 disconnect.mp3 ring.mp3 sd.mp3 usb.mp3 0_en.mp3 1_en.mp3 2_en.mp3 3_en.mp3 4_en.mp3 5_en.mp3 6_en.mp3 7_en.mp3 8_en.mp3 9_en.mp3 radio_en.mp3 linein_en.mp3 music_en.mp3 pc_en.mp3 rec_en.mp3 recplay_en.mp3 bt_en.mp3 connect_en.mp3 dis_en.mp3 fm_scan_en.mp3 prev_en.mp3 last_ch_en.mp3 mute_en.mp3 mute_off_en.mp3 next_en.mp3 next_ch_en.mp3 pause_en.mp3 play_en.mp3 rep_one_en.mp3 rep_all_en.mp3 usb_en.mp3 sd_en.mp3 voice_on_en.mp3 voice_off_en.mp3 normal_en.mp3 pop_en.mp3 rock_en.mp3 jazz_en.mp3 class_en.mp3 soft_en.mp3 vl_dec_en.mp3 vl_inc_en.mp3 vl_max_en.mp3 f_s_end_en.mp3 -key kpl_003_AC690X-7247.key
)

rem  -key kpl_003_AC690X-7247.key

::-format cfg
:: -read flash_r.bin 0-2M

if exist *.mp3 del *.mp3 
if exist *.PIX del *.PIX
if exist *.TAB del *.TAB
if exist *.res del *.res
if exist *.sty del *.sty
if exist jl_690x.bin del jl_690x.bin
if exist jl_cfg.bin del jl_cfg.bin


rename jl_isd.bin jl_690x.bin
bfumake.exe -fi jl_690x.bin -ld 0x0000 -rd 0x0000 -fo jl_690x.bfu
copy /b jl_690x.bfu+jl_flash_cfg.bin  jl_690x.bfu

@rem rename jl_isd.bin jl_cfg.bin
@rem bfumake.exe -fi jl_cfg.bin -ld 0x0000 -rd 0x0000 -fo jl_690x.bfu
@rem copy /b jl_690x.bfu+jl_flash_cfg.bin  jl_690x.bfu

IF EXIST no_isd_file del jl_690x.bin jl_cfg.bin
del no_isd_file


@rem format vm        //擦除VM 68K区域
@rem format cfg       //擦除BT CFG 4K区域
@rem format 0x3f0-2  //表示从第 0x3f0 个 sector 开始连续擦除 2 个 sector(第一个参数为16进制或10进制都可，第二个参数必须是10进制)




