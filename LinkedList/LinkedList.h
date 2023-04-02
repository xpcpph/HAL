#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include "../HAL/BasicDataTypes.h"

typedef struct _LinkedList{
    hal_void* data;
    struct _LinkedList* next; 
}LinkedList;


#endif
