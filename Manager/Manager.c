#include "../HAL/Manager/Manager.h"

/**内部使用*/
DriverMemoryManager *Pthis = hal_Null;
#define this(MemStruct) Pthis = MemStruct


/**外部调用*/

//主内存池的创建
DriverMemoryManager * MemoryStuctInit()
{
    if(Pthis != hal_Null)
    {
        DriverMemoryManager *Mem;
        Mem->MemoryObject.init = MemoryInit();
        
        Mem->MemoryObject.open = hal_Null;
        Mem->MemoryObject.close = hal_Null;
        Mem->MemoryObject.read = hal_Null;
        Mem->MemoryObject.write = hal_Null;

        Mem->DriverMemState = StateOK;
        hal_void * temp = _malloc(external,MEM2_MAX_SIZE);
        Mem->DriverMemPerused = 0;
        Mem->DriverAllocator = temp;
        Mem->DriverUsableStartAddress = temp;
        Mem->DriverUsableEndAddress = MemorySize;
        Mem->DriverMemLocation = external;
        this(Mem);
    }
    
    return Pthis;
    
}

DriverMemory* AllocFromFree(uint32_t size)
{
    DriverMemory *MP;
    MP = (DriverMemory*)Pthis->DriverAllocator;
    (*MP).StartAddress = (hal_uchar*)Pthis->DriverAllocator + (sizeof(DriverMemory)*8);
    (*MP).StopAddress = (hal_void*)((uint32_t)MP->StartAddress + (size * 8));
    return MP;
}


hal_void* __malloc(uint32_t size)
{
    DriverMemory *MP ;
    
    if (size == 0)
    {
        return hal_Null;
    }
    if (size % __HALMemoryAlignSize)
    {
        size = (size / __HALMemoryAlignSize + 1) * __HALMemoryAlignSize;
    }
    if (((uint32_t)((int)Pthis->DriverUsableEndAddress - (int)Pthis->DriverUsableStartAddress))<= size)
    {
        return hal_Null;
    }
    //size = size + 2 * sizeof(DriverMemory);
    MP = AllocFromFree(size);
    //MP.StartAddress = Pthis->DriverAllocator;
    //MP.StopAddress = (hal_void *)((uint32_t)MP.StartAddress + (size * 8));
    Pthis->DriverMemPerused = (uint8_t)(((MemorySize - ((uint32_t)MP->StopAddress - (uint32_t)MP->StartAddress)) / MemorySize));//更新内存使用率
    Pthis->DriverAllocator = ((hal_void*)(((int)MP->StopAddress) + 1));
    hal_printf("Malloc Address : 0X%p;\n", MP->StartAddress);
    return MP->StartAddress;
}

hal_bool __free(hal_void *Phead)
{
    DriverMemory* MP;
    MP = (DriverMemory*)((hal_uchar *)Phead - (sizeof(DriverMemory)));
    
    hal_printf("Phead:%p\n", Phead);
    hal_printf("sizeof(DriverMemory):%d\n", sizeof(DriverMemory));
    hal_printf("MP:%p\n", MP);
    hal_printf("MP->StartAddress:%p\n", MP->StartAddress);
    hal_printf("MP->MP->StopAddress:%p\n", MP->StopAddress);
    MP->StartAddress = hal_Null;
    MP->StopAddress = hal_Null;
    hal_printf("MP->StartAddress:%p\n", MP->StartAddress);
    hal_printf("MP->StopAddress:%p\n", MP->StopAddress);
    MP = hal_Null;
}

hal_void *refree(hal_void *Phead,hal_int size)
{

}