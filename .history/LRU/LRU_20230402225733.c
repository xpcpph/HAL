#include "../HAL/LRU/LRU.h"
#include "../HAL/Manager/Manager.h"

uint8_t LRUDriveManagerCount; //LRU设备管理器计数

//创建LRU任务
LRUList* LRUTaskCreate(LRUList* phead, LRUDriverManager* LRUdriverManager)
{
    if (LRUdriverManager == hal_Null)
    {
        return hal_Null;
    }
    LRUList* LRUTemp = LRUTaskFind(phead, (uint8_t)LRUdriverManager->DriverID);
    if (LRUTemp != hal_Null)
    {
        return LRUTemp;
    }
    if (LRUTemp == hal_Null)
    {
        LRUTemp = (LRUList*)malloc(sizeof(LRUList));
        LRUDriveManagerCount += 1;
    }
    if (LRUTemp == hal_Null)
    {
        return hal_Null;
    }

    LRUTemp->TaskID = LRUDriveManagerCount;
    LRUTemp->data = LRUdriverManager;
    LRUTemp->next = hal_Null;
        
    return LRUTemp;

}
LRUDriverManager b = { 0, 99, 0, hal_Null, hal_Null , hal_Null };

//LRU任务管理器的初始化     设置哨兵节点 哨兵节点的LRUDriveManagerCount为0
LRUList* LRUManagerInit(LRUDriverManager *LRUStruct)
{
    LRUList* LRUTemp;
    LRUDriveManagerCount = 0;
    LRUTemp = (LRUList*)malloc(sizeof(LRUList));
    LRUTemp->TaskID = LRUDriveManagerCount;
    LRUTemp->data = LRUStruct;
    LRUTemp->next = hal_Null;
    hal_printf("%d", LRUDriveManagerCount);
    LRUDriveManagerCount += 1;
    hal_printf("%d", LRUDriveManagerCount);
    return LRUTemp;
}

//LRU任务设备ID查找
LRUList* LRUTaskDriverIDFind(LRUList* phead, uint32_t DriverID)
{
    LRUList* temp = phead;
    while (1)
    {
        if (temp == hal_Null)
        {
            return hal_Null;
        }
        if (temp->TaskID == 0)
        {
            temp = temp->next;
            continue;
        }
        
        if (temp->data == hal_Null)
        {
            return hal_Null;
        }
        if (temp->data->DriverID == (uint32_t)DriverID)
        {
            return temp;
        }
        temp = temp->next;
        
    }
}

//LRU任务ID查找
LRUList* LRUTaskTaskIDFind(LRUList* phead, uint8_t TaskID)
{
    LRUList* temp = phead;
    while (1)
    {
        if (temp == hal_Null)
        {
            return hal_Null;
        }
        if (temp->TaskID == 0)
        {
            temp = temp->next;
            continue;
        }
        
        if (temp->data == hal_Null)
        {
            return hal_Null;
        }
        if (temp->TaskID == (uint8_t)TaskID)
        {
            return temp;
        }
        temp = temp->next;
        
    }
}

//LRU任务的添加
hal_bool LRUTaskAppend(LRUList* phead, LRUDriverManager* LRUdriveManager)
{
    LRUList* temp= hal_Null;
    temp = LRUTaskCreate(phead,LRUdriveManager);
    if (temp == hal_Null)
    {
        return hal_FALSE;
    }

    if (phead->next != hal_Null)
    {
        LRUList* first = LRUTaskTaskIDFind(phead, temp->TaskID);
        if (first == hal_Null)
        {
            first = phead->next;
            phead->next = temp;
            temp->next = first;
        }
        else
        {
            LRUList* temp2 = hal_Null;
            LRUList* temp3 = phead;
            while (1)
            {
                temp2 = temp3->next;
                hal_printf("temp->TaskID:%d\n", temp3->TaskID);
                hal_printf("temp1->TaskID:%d\n\n", temp2->TaskID);
                if (temp3 == hal_Null)
                {
                    return hal_FALSE;
                }
                if (temp3->TaskID == 0)
                {
                    temp3 = temp3->next;
                    continue;
                }

                if (temp3->data == hal_Null)
                    return hal_FALSE;


                if (temp2->TaskID == (uint8_t)first->TaskID)
                {
                    temp3->next = temp2->next;
                    first = phead->next;
                    phead->next = temp;
                    temp->next = first;
                    return hal_TRUE;
                }
                temp3 = temp3->next;

            }
        }
    }
    else
    {
        phead->next = temp;
    }
    return hal_TRUE;
}
//LRU任务的删除
hal_bool LRUTaskDelete(LRUList* phead, uint8_t TaskID)
{
    LRUList* temp1 = hal_Null;
    LRUList* temp = phead;
    while (1)
    {
        temp1 = temp->next;
        hal_printf("temp->TaskID:%d\n", temp->TaskID);
        hal_printf("temp1->TaskID:%d\n\n", temp1->TaskID);
        if (temp == hal_Null)
        {
            return hal_FALSE;
        }
        if (temp->TaskID == 0)
        {
            temp = temp->next;
            continue;
        }

        if (temp->data == hal_Null)
            return hal_FALSE;
        

        if (temp1->TaskID == (uint8_t)TaskID)
        {
            temp->next = temp1->next;
            hal_printf("--------------Delete temp->data --------------\n");
            hal_printf("temp->data:%p\n\n", temp->data);
            __free(temp->data);
            hal_printf("--------------Delete temp --------------\n");
            hal_printf("temp:%p\n\n", temp);
            __free(temp);
            
            return hal_TRUE;
        }
        
        temp = temp->next;
        
    }
        
}

//RUL任务的快照创建


//LRU任务的快照保存

