#include<stdlib.h>
#include "ListInternal.h"
#include "ListItr.h"
#include "genericDLL.h"

ListItr ListItrBegin(const List* _list)
{
	if(_list == NULL)
	{
		return NULL;
	}
	return (ListItr)(_list -> m_head.m_next);
}

ListItr ListItrEnd(const List* _list)
{
	if(_list == NULL)
	{
		return NULL;
	}
	return (ListItr)&(_list -> m_tail);
}

int ListItrEquals(const ListItr _a, const ListItr _b)
{
	return _a == _b;
}


ListItr ListItrNext(ListItr _itr)
{
	Node * temp;
	if(_itr == NULL)
	{
		return NULL;
	}
	temp = ((Node*)_itr) -> m_next ;
	return (ListItr)temp ;
}

ListItr ListItrPrev(ListItr _itr)
{
	Node * temp;
	if(_itr == NULL)
	{
		return NULL;
	}
	if(((Node*)_itr) ->m_prev -> m_prev == ((Node*)_itr) -> m_prev)
	{
		return _itr;
	}
	temp = ((Node*)_itr)-> m_prev;
	return (ListItr)temp ;
}

void* ListItrGet(ListItr _itr)
{
	if(_itr == NULL|| ((Node*)_itr) == ((Node*)_itr)-> m_next)
	{
		return NULL;
	}
	return ((Node*)_itr) -> m_data;
}

void* ListItrSet(ListItr _itr, void* _element)
{
	ListItr temp;
	if(_itr == NULL || _element == NULL|| ((Node*)_itr) == ((Node*)_itr)-> m_next)
	{
		return NULL;
	}
	temp = ((Node*)_itr)-> m_data;	
	((Node*)_itr) -> m_data = _element;
	return temp;
}

ListItr ListItrInsertBefore(ListItr _itr, void* _element)
{
	Node* nd;
	if(_itr == NULL || _element == NULL)
	{
		return NULL;
	}
	nd = (Node*)malloc( sizeof(Node));
	if(nd == NULL)
	{
		return NULL;
	}
	nd -> m_data = _element;
	swapPush( (Node*)_itr, nd);
	return (ListItr)nd;
}


void* ListItrRemove(ListItr _itr)
{
	ListItr  nd;
	if(_itr == NULL || ((Node*)_itr)  == ((Node*)_itr) -> m_next )
	{
		return NULL;
	}
	nd = ((Node*)_itr) -> m_data; 
	swapPop (( Node*)_itr); 
	free(_itr);
	return nd;
}



