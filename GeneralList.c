#include <stdio.h>/* for prints*/
#include <stdlib.h>/* for malloc*/
#include "ListItr.h"
#include "GeneralList.h"
#include "genericDLL.h"
#define TRUE 1
#define FALSE 0

 static int InnearForFind(int _bool, void* _context); 
 static int InnearForEach(int _bool, void* _context) ;
 static int InnearCount(int _bool, void* _context); 

typedef  int (*InnearFunction)(int _bool, void* _context);

struct Info
{
	ListItr m_begin;
	ListItr m_end;
	PredicateFunction m_func;
	void* m_context;
	InnearFunction m_innearFunc;
	void* m_innearContext;
};


ListItr General(Info* _info)
{
	int result;
	ListItr begin;
	void * data;
	begin = _info -> m_begin;
	while(begin != _info -> m_end)
	{
		data = ListItrGet(begin);
		result = _info -> m_func(data , _info -> m_context );
		result = _info -> m_innearFunc(result , _info -> m_innearContext);
		if(result == FALSE)
		{
			break;
		}
		begin = ListItrNext(begin);
	}
	return begin;
}

ListItr ListItrFindFirst(ListItr _begin, ListItr _end, PredicateFunction _predicate, void* _context)
{
	Info* inf;
	inf= (Info*)malloc( sizeof(Info));
	if(inf == NULL)
	{
		return _end;
	}
	inf -> m_begin = _begin;
	inf -> m_end = _end;
	inf -> m_func = _predicate;
	inf -> m_context = _context;
	inf -> m_innearFunc = InnearForFind;
	inf -> m_innearContext = NULL; 
	return General(inf);
}


ListItr ListItrForEach(ListItr _begin, ListItr _end, ListActionFunction _action, void* _context)
{
	Info* inf;
	inf= (Info*)malloc( sizeof(Info));
	if(inf == NULL)
	{
		return _end;
	}
	inf -> m_begin = _begin;
	inf -> m_end = _end;
	inf -> m_func = _action;
	inf -> m_context = _context;
	inf -> m_innearFunc = InnearForEach;
	inf -> m_innearContext = NULL; 
	return General(inf);

}

size_t ListItrCountIf(ListItr _begin, ListItr _end, PredicateFunction _predicate, void* _context)
{
	Info* inf;
	size_t count = 0;
	inf= (Info*)malloc( sizeof(Info));
	if(inf == NULL)
	{
		return ;
	}
	inf -> m_begin = _begin;
	inf -> m_end = _end;
	inf -> m_func = _predicate;
	inf -> m_context = _context;
	inf -> m_innearFunc = InnearCount;
	inf -> m_innearContext = &count; 
	General(inf);
	return count;
}

  static int InnearCount(int _bool, void* _context) 
 {
 	if (_bool == TRUE)
 	{
 		*(size_t*)_context += 1;
 	}
 	return TRUE;
 }
 

 static int InnearForEach(int _bool, void* _context) 
 {
 	return _bool ;
 }
 
  static int InnearForFind(int _bool, void* _context) 
 {
 	if (_bool == TRUE)
 	{
 		return FALSE;
 	}
 	return TRUE;
 }
 

