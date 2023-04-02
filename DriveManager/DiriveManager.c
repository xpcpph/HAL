#include "../hal/DriveManager/DriveManager.h"
#include "../hal/Manager/Manager.h"
#include "../HAL/LRU/LRU.h"

LRUList *Pthis = hal_Null;
#define this(This) Pthis =  This

LRUDriverManager * DriveManagerCreate(__IO uint16_t DriverID,
                            const __IO hal_char DriverName,
                            __IO uint16_t DriverHardwareState,
                            DriverManagerHardwareInfo *driverManagerHardwareInfo,
                            DriverObject *driverObject,
                            hal_void *UserDefinedFunction)
{
    LRUDriverManager *DriverManagerList;
    DriverManagerList = (LRUDriverManager *)__malloc(sizeof(LRUDriverManager));
    DriverManagerList->DriverID = DriverID;
    hal_strcopy(DriverManagerList->DriverName,DriverName) ;
    DriverManagerList->DriverHardwareState = DriverHardwareState;
    DriverManagerList->driverManagerHardwareInfo = driverManagerHardwareInfo;
    DriverManagerList->driverObject = driverObject;
    DriverManagerList->userDefinedFunction = UserDefinedFunction;

    return DriverManagerList;
}

//设备管理器初始化
hal_void DriverManagerInit()
{
    LRUDriverManager * DriverManagerListInit;
    DriverManagerListInit = DriveManagerCreate(0,"DriverManager",hal_Null,hal_Null,hal_Null,hal_Null);
    LRUList *DriverManagerList =  LRUManagerInit(DriverManagerListInit);
    this(DriverManagerList);
}

//添加设备
hal_bool DriverManagerAppend(__IO uint16_t DriverID,
                            const __IO hal_char DriverName,
                            __IO uint16_t DriverHardwareState,
                            DriverManagerHardwareInfo *driverManagerHardwareInfo,
                            DriverObject *driverObject,
                            hal_void *UserDefinedFunction)
{
    LRUDriverManager * DriverManagerNode = DriveManagerCreate(DriverID,DriverName,DriverHardwareState,driverManagerHardwareInfo,driverObject,UserDefinedFunction);
    if(!LRUTaskAppend(Pthis,DriverManagerNode)){
        hal_ERROR("Driver Manager Append Failed!"); //设备管理器添加失败
        return hal_FALSE;
    }
    return hal_TRUE;
}

//添加设备
hal_bool DriverManagerStructAppend(LRUDriverManager * DriverManagerNode)
{
    if(!LRUTaskAppend(Pthis,DriverManagerNode)){
        hal_ERROR("Driver Manager Append Failed!"); //设备管理器添加失败
        return hal_FALSE;
    }
    return hal_TRUE;
}

//删除设备
hal_bool DriverManagerDelete(uint8_t TaskID)
{
    if(!LRUTaskDelete(Pthis,TaskID)){
        hal_ERROR("Driver Manager Delete Failed!"); //设备管理器删除失败
        return hal_FALSE;
    }
    return hal_TRUE;
}

