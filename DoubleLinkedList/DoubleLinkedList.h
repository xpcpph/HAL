#ifndef __DOUBLELINKEDLIST_H__
#define __DOUBLELINKEDLIST_H__

#include "../HAL/BasicDataTypes.h"
#include "../HAL/Manager/Manager.h"

typedef struct _DoubleLinkedList{
    hal_void* data;
    struct _DoubleLinkedList* LinkedListNext;
    struct _DoubleLinkedList* LinkedListPrev;
}DoubleLinkedList;

/*函数*/
hal_void DoubleLinkedListInit(DoubleLinkedList** pphead);//链表的初始化,创建哨兵节点
/*------------------------------插入 函数 开始------------------------------*/
//双向链表尾部
hal_void DoubleLinkedListInterpositionTail(DoubleLinkedList* phead,hal_void *data);
//双向链表头部
hal_void DoubleLinkedListInterpositionIndex(DoubleLinkedList* phead,hal_void *data);
/*------------------------------插入 函数 结束------------------------------*/
/*------------------------------删除 函数 开始------------------------------*/
//双向链表尾部
hal_void DoubleLinkedListDeleteTail(DoubleLinkedList* phead);
//双向链表头部
hal_void DoubleLinkedListDeleteIndex(DoubleLinkedList* phead);
/*------------------------------删除 函数 结束------------------------------*/

#endif
