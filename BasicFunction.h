#ifndef __BASICFUNCTION_H__
#define __BASICFUNCTION_H__
#include "../HAL/config.h"

#ifdef  USE_FULL_ASSERT
#define assert_param(expr) ((expr) ? (void)0 : assert_failed((uint8_t *)__FILE__, __LINE__))
//如果使用,就要实现    assert_failed()
void assert_failed(uint8_t* file, uint32_t line);
#else
  #define assert_param(expr) ((void)0)
#endif

/*Debug*/
#ifdef DEBUG
    #define hal_printf(format, ...) printf(format, ##__VA_ARGS__)
#else
    #define hal_printf(format, ...)
#endif

#ifndef assert
hal_bool assert(hal_void *Struct)
{
    if((Struct) == hal_Null)
    {
        hal_FALSE;
    }
    return hal_TRUE;
}
#endif

void hal_assert(void)
{
    #ifdef DEBUG_MODE
        *(char *)(0)=1;
    #endif
}

void hal_ERROR(hal_char fmt[])
{
	PX_ASSERT();
}

hal_char* hal_strcopy(hal_char* dst, const hal_char*str)
{
    hal_char* strDestCopy = dst;

    if ((hal_Null == dst) || (hal_Null == str))
    {
        return ;
    }

    while ((*dst++ = *str++) != '\0');
    dst = strDestCopy;
    return strDestCopy;
}
#endif
