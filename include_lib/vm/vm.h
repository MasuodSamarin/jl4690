#ifndef _VM_H_
#define _VM_H_

#include "typedef.h"
#include "peripherals/winbond_flash.h"
//
//#ifndef  AT_VM
//#include "mango_dev_spi0flash.h"
//#endif



typedef enum _vm_err
{
    VM_ERR_NONE = 0,
    VM_INDEX_ERR,
    VM_INDEX_EXIST,
    VM_READ_NO_INDEX,
    VM_READ_DATA_ERR,
    VM_WRITE_OVERFLOW,
    VM_ERR_INIT,
    VM_ERR_PROTECT
} vm_err;

typedef u8 vm_hdl;

/*��ʽ��VM_����*/
extern void vm_eraser(void);

/*
ÿ���ϵ��ʼ��VMϵͳ,
need_defrag_when_write_full: ��vm����д��ʱ�Ƿ���Ҫ������Ƭ
*/
extern void vm_run_mode_and_keyt_init(u8 mode);
extern vm_err vm_init(u32 vm_addr, u32 spi_base, u8 mode, bool need_defrag_when_write_full);

/*
�� vm_write,vm_read ǰ�����ȴ� ָ��index ��þ��,
�����δ�: vm_read/vm_write(vm_open(index,data_len),data_buf)
*/
extern vm_hdl vm_open(u8 index, u8 data_len);

/*�������õ���vm_write,vm_read ʱ���Թرվ���ͷ��ڴ�*/
extern vm_err vm_close(vm_hdl hdl);

/*��д����������������ʾʵ�ʶ�д���ȣ����ظ�����ʾ����*/
extern s32 vm_write(vm_hdl hdl, const void *data_buf);
extern s32 vm_read(vm_hdl hdl, void * data_buf);

/*�ֶ�������Ƭ*/
extern vm_err vm_defrag(void);

/*��� vm ���� ʹ�����, ����ʹ�õİٷֱ�*/
extern int vm_status(void);

extern const struct DEV_IO * dev_reg_vm(void *parm);


bool sfc_erase(FLASH_ERASER cmd, u32 addr);
u32 sfc_write(const u8 *buf, u32 adr, u32 len);
u32 sfc_read(u8 *buf, u32 adr, u32 len);

#endif  //_VM_H_



