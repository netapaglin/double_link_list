#ifndef __LIST_INTERNAL_H__
#define __LIST_INTERNAL_H__
#include "genericDLL.h"

struct Node
{
	void* m_data;
	Node* m_next;
	Node* m_prev;
};

struct List
{
	Node m_head;
	Node m_tail;
};


ListResult swapPush( Node* _ref, Node* _newNode);
ListResult swapPop ( Node* _ref);


#endif /* __LIST_INTERNAL__ */
