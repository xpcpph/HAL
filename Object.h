#ifndef __OBJCET_H_
#define __OBJCET_H_

#include "../HAL/BasicDataTypes.h"

typedef struct _DriverManager{
    __IO uint16_t DriverPortClock; //端口时钟
    __IO uint16_t DriverPorts; //设备所端口 eg:GPIOA,GPIOB...
    __IO uint16_t DriverPinPort; //设备具体端口     eg:GPIO_Pin_1,GPIO_Pin_2...
        //  uint16_t Driver
}DriverManagerHardwareInfo;     //设备管理器结构体

typedef struct _DriverObject{
    hal_void (*init)();     //设备初始化函数的接口
    hal_void (*open)();     //打开函数
    hal_void (*close)();    //关闭函数
    hal_void (*read)();     //读取函数
    hal_void (*write)();    //写入函数
    
}DriverObject;


#endif //
