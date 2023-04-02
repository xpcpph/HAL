#ifndef __LRU_H__
#define __LRU_H__

#include "../HAL/BasicDataTypes.h"
#include "../HAL/Object.h"

#define LRUDriverNameSize 25

typedef struct _LRUDriverManager{
    __IO uint16_t DriverID; //设备ID  设备的唯一标识,用快速定位一个设备的位置
    __IO hal_char DriverName[LRUDriverNameSize];        //设备名称      用于注册设备和删除设备
    __IO uint16_t DriverHardwareState; //是否是硬件设备
    /**
     * ManagerHardwareInfo = hal_null 就是不操作任何硬件,只在软件层面上
     * ManagerHardwareInfo = 0X...... 是操作硬件
     */
    DriverManagerHardwareInfo *driverManagerHardwareInfo;
    /**
     * driverObject 是向上层提供接口
     */
    DriverObject *driverObject;
    //接收的是结构体
    hal_void *userDefinedFunction;
} LRUDriverManager;

typedef struct _LRUList{
    uint8_t TaskID;
    LRUDriverManager *data;
    struct _LRUList *next;
}LRUList;

LRUList* LRUManagerInit(LRUDriverManager *LRUStruct);//LRU任务管理器的初始化     设置哨兵节点 哨兵节点的LRUDriveManagerCount为0
LRUList* LRUTaskDriverIDFind(LRUList* phead, uint32_t DriverID);//LRU任务设备ID查找
LRUList* LRUTaskTaskIDFind(LRUList* phead, uint8_t TaskID);//LRU任务ID查找
hal_bool LRUTaskAppend(LRUList* phead, LRUDriverManager* LRUdriveManager);//LRU任务的添加
hal_bool LRUTaskDelete(LRUList* phead, uint8_t TaskID);//LRU任务的删除
#endif
