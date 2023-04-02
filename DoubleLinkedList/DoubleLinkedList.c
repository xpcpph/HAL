#include "../HAL/DoubleLinkedList/DoubleLinkedList.h"
#include "../HAL/BasicFunction.h"

//创建一个指向为空的节点
DoubleLinkedList* BuyListNode(hal_void *addr) {

	DoubleLinkedList* node = (DoubleLinkedList*)malloc(sizeof(DoubleLinkedList));
	node->LinkedListNext = hal_Null;//前后的指针先置空，到了操作接口里面，我们再操作这些指针
	node->LinkedListPrev = hal_Null;
	node->data = addr;//数据为传入的结构体或数据
	return node;
}

//双向链表的初始化
hal_void DoubleLinkedListInit(DoubleLinkedList** pphead)
{
    //这是一个链表头的初始化
    hal_int a = hal_Null;
	*pphead = BuyListNode(&a);
	(*pphead)->LinkedListNext = *pphead;
	(*pphead)->LinkedListPrev = *pphead;
	//->优先级和*相同，所以括号一下
}

/*------------------------------插入 函数 开始------------------------------*/
//双向链表尾部
hal_void DoubleLinkedListInterpositionTail(DoubleLinkedList* phead,hal_void *data)
{
    DoubleLinkedList *NewStruct = BuyListNode(data);
    if(assert(NewStruct))
    {
        hal_ERROR("Failed to create node"); //创建节点失败
        return ;
    }
    DoubleLinkedList* tail = phead->LinkedListPrev;

    tail->LinkedListNext = NewStruct;
    NewStruct->LinkedListPrev = tail;
    NewStruct->LinkedListNext = phead;
    phead->LinkedListPrev = NewStruct;
}
//双向链表头部
hal_void DoubleLinkedListInterpositionIndex(DoubleLinkedList* phead,hal_void *data)
{
    DoubleLinkedList *NewStruct = BuyListNode(data);
    if(assert(NewStruct))
    {
        hal_ERROR("Failed to create node"); //创建节点失败
        return ;
    }
    DoubleLinkedList *first = phead->LinkedListNext;

    phead->LinkedListNext = NewStruct;
    NewStruct->LinkedListPrev = phead;
    NewStruct ->LinkedListNext = first;
    first->LinkedListPrev = NewStruct;
}
/*------------------------------插入 函数 结束------------------------------*/

/*------------------------------删除 函数 开始------------------------------*/
//双向链表尾部
hal_void DoubleLinkedListDeleteTail(DoubleLinkedList* phead)
{
    if(phead->LinkedListNext == phead)
    {
        hal_ERROR("Only the head node is left"); //只剩头结点了
        return ;
    }
    DoubleLinkedList* tail = phead->LinkedListPrev;
    phead->LinkedListPrev = tail->LinkedListPrev;
    tail->LinkedListPrev->LinkedListNext = phead;
    
}
//双向链表头部
hal_void DoubleLinkedListDeleteIndex(DoubleLinkedList* phead)
{
    if(phead->LinkedListNext == phead)
    {
        hal_ERROR("Only the head node is left"); //只剩头结点了
        return ;
    }
    DoubleLinkedList* first = phead->LinkedListNext;
    phead->LinkedListNext = first->LinkedListNext;
    first->LinkedListNext->LinkedListPrev = phead;

}
/*------------------------------删除 函数 结束------------------------------*/

/*------------------------------查询 函数 开始------------------------------*/
//双向链表尾部

//双向链表头部

//双向链表指定位置

/*------------------------------查询 函数 结束------------------------------*/