#include <stdio.h>/* for prints*/
#include<stdlib.h>/* size_t malloc*/
#include "genericDLL.h"
#include "ListInternal.h"

static ListResult PopCheckParems(List* _list, void** _pItem);

List* ListCreate(void)
{
	List * lst;
	lst= (List*)malloc(sizeof(List));
	if(lst == NULL)
	 {
	     return NULL;
	 }
	 lst ->m_head.m_next = &(lst -> m_tail);
	 lst -> m_tail.m_prev = &(lst -> m_head);
	 lst-> m_head.m_prev = &(lst -> m_head);
	 lst-> m_tail.m_next = &(lst -> m_tail);
	 return lst;
}

void ListDestroy(List** _pList, void (*_elementDestroy)(void* _item))
{
	Node* nd;

	if(_pList == NULL || *_pList == NULL)
	{
		return;
	}
	nd = (*_pList) ->m_head.m_next;
	while (nd != &((*_pList) -> m_tail ))
	{
		if(_elementDestroy != NULL)
		{
			_elementDestroy(nd -> m_data);
		}
		nd= nd ->m_next;
		free(nd -> m_prev);
	}
	free(*_pList);
	*_pList = NULL;
}

ListResult ListPushHead(List* _list, void* _item)
{
	Node* nd;
	Node* ref;
	if(_list == NULL )
	{
		return LIST_UNINITIALIZED_ERROR;
	}
	if (_item == NULL)
	{
		return LIST_NULL_ELEMENT_ERROR;
	}
	nd = (Node*)malloc( sizeof(Node));
	if(nd == NULL)
	{
		return LIST_ALLOCATION_ERROR;
	}
	nd -> m_data = _item;
	ref = _list->m_head.m_next;
	swapPush(ref, nd);
	return LIST_SUCCESS;
}

ListResult ListPushTail(List* _list, void* _item)
{
	Node* nd;
	Node* ref;
	if(_list == NULL )
	{
		return LIST_UNINITIALIZED_ERROR;
	}
	if (_item == NULL)
	{
		return LIST_NULL_ELEMENT_ERROR;
	}
	nd = (Node*)malloc( sizeof(Node));
	if(nd == NULL)
	{
		return LIST_ALLOCATION_ERROR;
	}
	nd -> m_data = _item;
	ref = &_list->m_tail;
	swapPush(ref, nd);
	return LIST_SUCCESS;
}

ListResult ListPopHead(List* _list, void** _pItem)
{
	Node* ref = NULL;
	ListResult  checkParams;
	if ((checkParams = PopCheckParems(_list, _pItem)) != LIST_SUCCESS)
	{
		return checkParams;
	}
	ref = _list->m_head.m_next;
	*_pItem = ref -> m_data;
	swapPop( ref);
	free(ref);
	return LIST_SUCCESS;
}


ListResult ListPopTail(List* _list, void** _pItem)
{
	Node* ref;
	ListResult  checkParams;
	if ((checkParams = PopCheckParems(_list, _pItem)) != LIST_SUCCESS)
	{
		return checkParams;
	}
	ref = _list->m_tail.m_prev;
	*_pItem = ref -> m_data;
	swapPop ( ref);
	free(ref);
	return LIST_SUCCESS;
}

size_t ListSize(const List* _list)
{
	Node* nd;
	size_t count = 0;
	if( _list != NULL)
	{
		nd = (_list->m_head.m_next);
		while (nd  != &_list -> m_tail )
		{
			nd= nd ->m_next;
			++count;
		}	
		return count;
	}
}

ListResult swapPush( Node* _ref, Node* _newNode)
{
	if (_ref == NULL || _newNode == NULL)
	{
		return LIST_NULL_ELEMENT_ERROR;
	}
    _newNode-> m_prev =_ref->m_prev;
	_newNode->m_next = _ref ;
	_ref ->m_prev->m_next = _newNode;
	_ref->m_prev= _newNode;
	return LIST_SUCCESS;
}

ListResult swapPop( Node* _ref)
{
	if (_ref == NULL)
	{
		return LIST_NULL_ELEMENT_ERROR;
	}
	_ref ->m_next -> m_prev = _ref-> m_prev;
	_ref -> m_prev -> m_next = _ref -> m_next;
	return LIST_SUCCESS;
}

static ListResult PopCheckParems(List* _list, void** _pItem)
{
		if( _list == NULL)
	{
		return LIST_UNINITIALIZED_ERROR;
	}
	if (_pItem == NULL)
	{
		return LIST_NULL_ELEMENT_ERROR;
	}
	if(_list ->m_head.m_next == &(_list -> m_tail))
	{
		return LIST_UNDERFLOW_ERROR;
	} 
	return LIST_SUCCESS;
}




