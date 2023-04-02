#ifndef __DriveManager_H__
#define __DriveManager_H__
#include "../HAL/config.h"
#include "../HAL/BasicDataTypes.h"
#include "../HAL/BasicFunction.h"
#include "../HAL/Object.h"
#include "../HAL/LRU/LRU.h"

#define DriveManagerMemorySize   2*1024

hal_void DriverManagerInit();

#endif
