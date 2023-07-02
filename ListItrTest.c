#include <stdio.h>/* for prints*/
#include "genericDLL.h"
#include "ListItr.h"
#include "ListInternal.h"
#include "GeneralList.h"
#define TRUE 1
#define FALSE 0

void TestListItrBegin();
void TestListItrBeginNull();

void TestListItrEmptyList();

void TestListItrEnd();

void TestEquallsTrue();
void TestEquallsFalse();

void TestItrNext();
void TestItrNextNull();
void TestItrNextEnd();

void TestItrPrev();
void TestItrPrevNull();
void TestItrPrevBegin();

void TestItrGet();
void TestItrGetNull();
void TestItrGetEnd();

void TestItrSetReturn();
void TestItrSetInput();
void TestItrSetNull();

void TestItrInsert();
void TestItrInsertReturn();
void TestItrInsert2();

void TestItrRemoveReturnValue();

void TestItrFindFirstExist();
void TestItrFindFirstNotExist();

void TestItrForEach();

void TestItrCount();

int main()
{

	TestListItrBegin();
	TestListItrBeginNull();
	
	TestListItrEmptyList();
	
	TestListItrEnd();

	TestEquallsTrue();
	TestEquallsFalse();
	
	TestItrNext();
	TestItrNextNull();
	TestItrNextEnd();
	
	TestItrPrev();
	TestItrPrevNull();
	TestItrPrevBegin();
	
	TestItrGet();
	TestItrGetNull();
	TestItrGetEnd();
	
	TestItrSetReturn();
	TestItrSetInput();
	TestItrSetNull();
	
	TestItrInsert();
	TestItrInsertReturn();
	TestItrInsert2();
	
	TestItrRemoveReturnValue(); 

	TestItrFindFirstExist();
	TestItrFindFirstNotExist();
	
	TestItrForEach();
	
	TestItrCount();
	
	return 1;
}

 static int CheckForCount(void * _element, void* _context) 
 {
 	if (*(int*)_element == *(int*)_context)
 	{
 		return TRUE;
 	}
 	return FALSE;
 }

 
void TestItrCount()
{
	List * lst;
	ListItr * x;
	int toFind = 7;
	size_t res;
	int a = 1, b = 5 , c = 7 , d = 2 , e = 7 , f = 9;
	lst =	ListCreate();
	ListPushHead(lst, &a);
	ListPushHead(lst, &b);
	ListPushHead(lst, &c);
	ListPushHead(lst, &d);
	ListPushHead(lst, &e);
	ListPushHead(lst, &f);
	res = ListItrCountIf(ListItrBegin(lst), ListItrEnd(lst), CheckForCount , (void*)&toFind);
	printf("count - %ld\n", res);
	
	ListDestroy(&lst , NULL);
}


 static int ForEachPrintInt(void * _element, void* _context) 
 {
	if (_element == NULL)
	{
		return FALSE;
	}
	printf("%d \n", *(int*)_element);
 	return TRUE;
 }

 
void TestItrForEach()
{
	List * lst;
	ListItr * x;
	int a = 1, b = 5 , c = 3 , d = 2 , e = 7;
	lst =	ListCreate();
	ListPushHead(lst, &a);
	ListPushHead(lst, &b);
	ListPushHead(lst, &c);
	ListPushHead(lst, &d);
	ListPushHead(lst, &e);
	 ListItrForEach(ListItrBegin(lst), ListItrEnd(lst), ForEachPrintInt ,NULL);

	ListDestroy(&lst , NULL);
}


 static int CheckForFindInt(void * _element, void* _context) 
 {
 	if (*(int*)_element == *(int*)_context)
 	{
 		return TRUE;
 	}
 	return FALSE;
 }

 
void TestItrFindFirstNotExist()
{
	List * lst;
	ListItr * x;
	int a = 1, b = 5 , c = 3 , d = 2 , e = 4;
	int toFind = 9;
	lst =	ListCreate();
	ListPushHead(lst, &a);
	ListPushHead(lst, &b);
	ListPushHead(lst, &c);
	ListPushHead(lst, &d);
	ListPushHead(lst, &e);
	x = ListItrFindFirst(ListItrBegin(lst), ListItrEnd(lst), CheckForFindInt , (void*)&toFind);
	if(x == ListItrEnd(lst))
	 {
	 	printf(" test Find first not exist-PASS\n");
	 }else
	 {
	 	printf(" test Find first not exist-FAIL\n");
	 }
	ListDestroy(&lst , NULL);
}

 
void TestItrFindFirstExist()
{
	List * lst;
	ListItr * x;
	int a = 1, b = 5 , c = 3 , d = 2 , e = 4;
	int toFind = 3;
	lst =	ListCreate();
	ListPushHead(lst, &a);
	ListPushHead(lst, &b);
	ListPushHead(lst, &c);
	ListPushHead(lst, &d);
	ListPushHead(lst, &e);
	x = ListItrFindFirst(ListItrBegin(lst), ListItrEnd(lst), CheckForFindInt , (void*)&toFind);
	if(x != ListItrEnd(lst))
	 {
	 	printf(" test Find first exist-PASS\n");
	 }else
	 {
	 	printf(" test Find first exist-FAIL\n");
	 }
	ListDestroy(&lst , NULL);
}



/*******************************************************************************************************/
void TestItrRemoveReturnValue()
{
	List * lst;
	Node* x ;
	Node* y;
	int a = 1, b = 5 , c = 3 , d = 4;
	lst =	ListCreate();
	ListPushHead(lst, &a);
	ListPushHead(lst, &b);
	ListPushHead(lst, &c);
	x = (Node*)ListItrBegin(lst);
	ListItrRemove(x);
	x = (Node*)ListItrBegin(lst);
	if(*(int*)ListItrGet(x)  == 5)
	 {
	 	printf(" test remove -PASS\n");
	 }else
	 {
	 	printf(" test remove-FAIL\n");
	 }
	ListDestroy(&lst , NULL); 
}


void TestItrInsert2()
{
	List * lst;
	Node * x, * y , *z ;
	int a = 1, b = 5 , c = 3, d = 4;
	lst =	ListCreate();
	ListPushHead(lst, &a);
	ListPushHead(lst, &b);
	x = (Node*)ListItrEnd(lst);
	x= ListItrPrev(x);
	/*	printf("%d\n" ,*(int*)ListItrGet(x)  );         */
	x= ListItrPrev(x);
	ListItrInsertBefore(x, &c);
	if(*(int*)ListItrGet(ListItrBegin(lst))  == 3)
	 {
	 	printf(" test insert 2 -PASS\n");
	 }else
	 {
	 	printf(" test insert 2-FAIL\n");
	 }
	ListDestroy(&lst , NULL); 
}


void TestItrInsert()
{
	List * lst;
	Node * x ;
	Node * y;
	int a = 1, b = 5 , c = 3;
	lst =	ListCreate();
	ListPushHead(lst, &a);
	ListPushHead(lst, &b);
	x = (Node*)ListItrEnd(lst);
	ListItrInsertBefore(x, &c);
	y = ListItrPrev(ListItrEnd(lst));
	if(*(int*)ListItrGet(y)  == 3)
	 {
	 	printf(" test insert -PASS\n");
	 }else
	 {
	 	printf(" test insert-FAIL\n");
	 }
	ListDestroy(&lst , NULL); 
}

void TestItrInsertReturn()
{
	List * lst;
	ListItr x, y, z ;

	int a = 1, b = 5 , c = 3;
	lst =	ListCreate();
	ListPushHead(lst, &a);
	ListPushHead(lst, &b);
	x = ListItrEnd(lst);
	y = ListItrInsertBefore(x, &c);
	z = ListItrPrev(ListItrEnd(lst));
/*	z = ListItrPrev(z);  */
	if(y == z )
	 {
	 	printf(" test insert return -PASS\n");
	 }else
	 {
	 	printf(" test insert return -FAIL\n");
	 }
	ListDestroy(&lst , NULL); 
}




void TestItrSetNull()
{
	List * lst;
	Node * x;
	int item;
	int a = 1, b = 5 , c = 3;
	lst =	ListCreate();
	ListPushHead(lst, &a);
	ListPushHead(lst, &b);
	x = (Node*)ListItrBegin(lst);
	if(ListItrSet(NULL , &c)  == NULL)
	 {
	 	printf(" test Set return null -PASS\n");
	 }else
	 {
	 	printf(" test Set return null-FAIL\n");
	 }
	ListDestroy(&lst , NULL);
}


void TestItrSetInput()
{
	List * lst;
	Node * x;
	int item;
	int a = 1, b = 5 , c = 3;
	lst =	ListCreate();
	ListPushHead(lst, &a);
	ListPushHead(lst, &b);
	x = (Node*)ListItrBegin(lst);
	ListItrSet(x , &c);
	if(*(int*)ListItrGet(x)  == 3)
	 {
	 	printf(" test Set input  -PASS\n");
	 }else
	 {
	 	printf(" test Set input-FAIL\n");
	 }
	ListDestroy(&lst , NULL);
}


void TestItrSetReturn()
{
	List * lst;
	Node * x;
	int item;
	int a = 1, b = 5 , c = 3;
	lst =	ListCreate();
	ListPushHead(lst, &a);
	ListPushHead(lst, &b);
	x = (Node*)ListItrBegin(lst);
	if(*(int*)ListItrSet(x , &c)  == 5)
	 {
	 	printf(" test Set return-PASS\n");
	 }else
	 {
	 	printf(" test Set return-FAIL\n");
	 }
	ListDestroy(&lst , NULL);
}


void TestItrGetEnd()
{
	List * lst;
	Node * x;
	int item;
	int a = 1, b = 5 , c = 3;
	lst =	ListCreate();
	ListPushHead(lst, &a);
	ListPushHead(lst, &b);
	x =ListItrNext(ListItrBegin(lst));
	x = ListItrNext(x);
	if(ListItrGet(x)  == NULL)
	 {
	 	printf(" test Get end -PASS\n");
	 }else
	 {
	 	printf(" test Get end -FAIL\n");
	 }
	ListDestroy(&lst , NULL);
}

void TestItrGetNull()
{
	List * lst;
	Node * x;
	int item;
	int a = 1, b = 5 , c = 3;
	lst =	ListCreate();
	ListPushHead(lst, &a);
	ListPushHead(lst, &b);
	x = (Node*)ListItrBegin(lst);
	if(ListItrGet(NULL)  == NULL)
	 {
	 	printf(" test Get null -PASS\n");
	 }else
	 {
	 	printf(" test Get null -FAIL\n");
	 }
	ListDestroy(&lst , NULL);
}

void TestItrGet()
{
	List * lst;
	Node * x;
	int item;
	int a = 1, b = 5 , c = 3;
	lst =	ListCreate();
	ListPushHead(lst, &a);
	ListPushHead(lst, &b);
	x = (Node*)ListItrBegin(lst);
	if(*(int*)ListItrGet(x)  == 5)
	 {
	 	printf(" test Get-PASS\n");
	 }else
	 {
	 	printf(" test Get -FAIL\n");
	 }
	ListDestroy(&lst , NULL);
}

void TestItrPrevBegin()
{
	List * lst;
	ListItr x;
	int item;
	int a = 1, b = 5 , c = 3;
	lst =	ListCreate();
	ListPushHead(lst, &a);
	ListPushHead(lst, &b);
	x =ListItrPrev(ListItrEnd(lst));
	x =ListItrPrev(x);
	if(ListItrPrev(x)  == ListItrPrev(x))
	 {
	 	printf(" test Prev begin  -PASS\n");
	 }else
	 {
	 	printf(" test Prev begin -FAIL\n");
	 }
	ListDestroy(&lst , NULL);
}


void TestItrPrevNull()
{
	List * lst;
	ListItr x;
	int item;
	int a = 1, b = 5 , c = 3;
	lst =	ListCreate();
	ListPushHead(lst, &a);
	ListPushHead(lst, &b);
	x =ListItrPrev(ListItrEnd(lst));
	if(ListItrPrev(NULL)  == NULL)
	 {
	 	printf(" test Prev null -PASS\n");
	 }else
	 {
	 	printf(" test Prev null -FAIL\n");
	 }
	ListDestroy(&lst , NULL);
}


void TestItrPrev()
{
	List * lst;
	ListItr x;
	int item;
	int a = 1, b = 5 , c = 3;
	lst =	ListCreate();
	ListPushHead(lst, &a);
	ListPushHead(lst, &b);
	x =ListItrPrev(ListItrEnd(lst));
	x =ListItrPrev(x);
	if(x  == ListItrBegin(lst))
	 {
	 	printf(" test Prev-PASS\n");
	 }else
	 {
	 	printf(" test Prev -FAIL\n");
	 }
	ListDestroy(&lst , NULL);
}


void TestItrNextEnd()
{
	List * lst;
	ListItr x , y;
	int a = 1, b = 5 , c = 3;
	lst =	ListCreate();
	ListPushHead(lst, &a);
	ListPushHead(lst, &b);
	ListPushHead(lst, &c);
	x =ListItrNext(ListItrBegin(lst));
	x = ListItrNext(x);
	y = ListItrNext(x);
	if(ListItrNext(x) == ListItrNext(y))
	 {
	 	printf(" test Next end -PASS\n");
	 }else
	 {
	 	printf(" test Next end -FAIL\n");
	 }
	ListDestroy(&lst , NULL);
}



void TestItrNextNull()
{
	List * lst;
	ListItr x;
	int a = 1, b = 5 , c = 3;
	lst =	ListCreate();
	ListPushHead(lst, &a);
	ListPushHead(lst, &b);
	ListPushHead(lst, &c);
	x =ListItrNext(ListItrBegin(lst));
	x = ListItrNext(x);
	if(ListItrNext(NULL) == NULL)
	 {
	 	printf(" test Next null -PASS\n");
	 }else
	 {
	 	printf(" test Next null -FAIL\n");
	 }
	ListDestroy(&lst , NULL);
}


void TestItrNext()
{
	List * lst;
	ListItr x;
	int a = 1, b = 5 , c = 3;
	lst =	ListCreate();
	ListPushHead(lst, &a);
	ListPushHead(lst, &b);
	ListPushHead(lst, &c);
	x =ListItrNext(ListItrBegin(lst));
	x = ListItrNext(x);
	x = ListItrNext(x);
	if(x == ListItrEnd(lst))
	 {
	 	printf(" test Next-PASS\n");
	 }else
	 {
	 	printf(" test Next -FAIL\n");
	 }
	ListDestroy(&lst , NULL);
}


void TestEquallsFalse()
{
	List * lst;
	int item;
	int a = 1, b = 5 , c = 3;
	lst =	ListCreate();
	ListPushHead(lst, &a);

	if(ListItrEquals(ListItrEnd(lst), ListItrBegin(lst))  == 0)
	 {
	 	printf(" test Equal false-PASS\n");
	 }else
	 {
	 	printf(" test Equal false -FAIL\n");
	 }
	ListDestroy(&lst , NULL);
}


void TestEquallsTrue()
{
	List * lst;
	int item;
	int a = 1, b = 5 , c = 3;
	lst =	ListCreate();
	if(ListItrEquals(ListItrEnd(lst), ListItrBegin(lst))  == 1)
	 {
	 	printf(" test Equal true-PASS\n");
	 }else
	 {
	 	printf(" test Equal true -FAIL\n");
	 }
	ListDestroy(&lst , NULL);
}



void TestListItrEnd()
{
	List * lst;
	int item;
	int *ptr = &item;
	int a = 1, b = 5 , c = 3;
	lst =	ListCreate();
	ListPushHead(lst, &a);
	ListPushHead(lst, &b);
	ListPushHead(lst, &c);	
	if(ListItrEnd(lst)  != NULL)
	 {
	 	printf(" test ListItrEnd-PASS\n");
	 }else
	 {
	 	printf(" test ListItrEnd -FAIL\n");
	 }
	ListDestroy(&lst , NULL);
}


void TestListItrEmptyList()
{
	List * lst;
	int a = 1, b = 5 , c = 3;
	lst =	ListCreate();
	if(ListItrBegin(lst) == ListItrEnd(lst))
	 {
	 	printf(" test empty list-PASS\n");
	 }else
	 {
	 	printf(" test empty list -FAIL\n");
	 }
	ListDestroy(&lst , NULL);
}


void TestListItrBeginNull()
{
	List * lst;
	int item;
	int *ptr = &item;
	int a = 1, b = 5 , c = 3;
	lst =	ListCreate();
	ListPushHead(lst, &a);
	ListPushHead(lst, &b);
	ListPushHead(lst, &c);	
	if(ListItrBegin(NULL)  == NULL)
	 {
	 	printf(" test ListItrBegin Null -PASS\n");
	 }else
	 {
	 	printf(" test ListItrBegin Null -FAIL\n");
	 }
	ListDestroy(&lst , NULL);
}

void TestListItrBegin()
{
	List * lst;
	int item;
	int *ptr = &item;
	int a = 1, b = 5 , c = 3;
	lst =	ListCreate();
	ListPushHead(lst, &a);
	ListPushHead(lst, &b);
	ListPushHead(lst, &c);	
	if(ListItrBegin(lst)  != NULL)
	 {
	 	printf(" test ListItrBegin-PASS\n");
	 }else
	 {
	 	printf(" test ListItrBegin -FAIL\n");
	 }
	ListDestroy(&lst , NULL);
}
