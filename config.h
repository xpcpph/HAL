#ifndef __CONFIG_H__
#define __CONFIG_H__

/*Debug*/
//在BaseFunction中可以根据自己的需求修改
//#define DEBUG

/*Manager config*/
#define MEM2_MAX_SIZE 960*1024
#define MemorySize MEM2_MAX_SIZE                              //可管理内存的大小
#define MemoryInit ManagerInit
#define _malloc(mem,size)  memalloc(mem,size)                 //对物理内存申请操作
#define _free(mem,paddr) memfree(mem,paddr)                      //对物理内存释放操作
#define _realloc(mem,paddr,size) memrealloc(mem,paddr,size)                 //对物理旧内存重新获取操作

#endif