#ifndef __manager_H__
#define __manager_H__

#include "../HAL/config.h"
#include "../HAL/BasicDataTypes.h"
#include "../HAL/BasicFunction.h"
#include "../HAL/Object.h"

#define __HALMemoryAlignSize (sizeof(void *))

// #define DriverManaAlign     4         //对齐方式(以千字节为单位)  内存页的大小=内存大小/对齐方式

typedef struct _DriverMemory
{
    hal_void *StartAddress; //开始地址
    hal_void *StopAddress; //结束地址
}DriverMemory;  //各设备可用内存

enum ManaLocation{
    Interior,   //内部
    external,   //外部
    CCM,
};
#define IS_ManagerLocation(expr)    ((expr == Interior)&&(expr == external))


typedef struct _DriverMemoryManager{
    DriverObject MemoryObject;        
    uint8_t DriverMemState;              //内存状态
    uint8_t DriverMemPerused;  //内存的使用率
    hal_void *DriverAllocator; //分配开始地址
    hal_void *DriverUsableStartAddress;       //可用开始地址        (除存放地址页的大小所开始的地方)这里存放的是虚拟地址
    hal_void *DriverUsableEndAddress;         //可以结束地址
    enum ManaLocation DriverMemLocation;      //内存地址位置(内部/外部/CCM)
}DriverMemoryManager;     //设备管理器结构体

DriverMemoryManager *MemoryStuctInit();
hal_void* __malloc(uint32_t size)
hal_bool __free(hal_void *Phead)
hal_void *refree(hal_void *Phead,hal_int size)
#endif
