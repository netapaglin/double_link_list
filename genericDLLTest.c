#include <stdio.h>/* for prints*/
#include "genericDLL.h"

void TestCreate();

void TestPushHead();
void TestPushHeadNormal();
void TestPushHeadListNull();
void TestPushHeadItemNull();

void TestPushTail();
void TestPushTailNormal();
void TestPushTailLinstNull();
void TestPushTailItemNull();

void TestPopHead();
void TestPopHeadNormal();
void TestPopHeadListNull();
void TestPopHeadItemNull();
void TestPopHeadUnderFlow();

void TestPopTail();
void TestPopTailListNull();
void TestPopTailItemNull();
void TestPopTailUnderflow();

void TestSize();

void TestDoubleDestroy();
void TestDestroy();

int main (void)
{

	TestCreate();
	
	TestPushHead();
	TestPushHeadNormal();
	TestPushHeadListNull();
	TestPushHeadItemNull();

	TestPushTail();
	TestPushTailNormal();
	TestPushTailLinstNull();
	TestPushTailItemNull();

	TestPopHead();
	TestPopHeadNormal();
	TestPopHeadListNull();
	TestPopHeadItemNull();
	TestPopHeadUnderFlow();
	
	TestPopTail(); 
	TestPopTailListNull();
	TestPopTailItemNull();
	TestPopTailUnderflow();
	
	TestSize();
	
	TestDoubleDestroy();
	TestDestroy();
	
	return 1;
}

void TestDestroy()
{
	List * lst;
	int *ptr;
	int a = 1, b = 5 , c = 3;
	lst =	ListCreate();
	ListPushTail(lst, &a);
	ListPushTail(lst, &b);
	ListPushTail(lst, &c);
	ListDestroy(&lst , NULL);
	if(	lst   == NULL)
	 {
	 	printf(" test destroy -PASS\n");
	 }else
	 {
	 	printf(" test destroy -FAIL\n");
	 }
	
}


void TestDoubleDestroy()
{
	List * lst;
	int item;
	int *ptr = &item;
	int a = 1, b = 5 , c = 3;
	lst =	ListCreate();
	ListPushTail(lst, &a);
	ListPushTail(lst, &b);
	ListPushTail(lst, &c);
	ListDestroy(&lst , NULL);
	ListDestroy(&lst , NULL);
	printf(" test Double Destroy -PASS\n");
}

void TestSize()
{
	List * lst;
	int *ptr;
	int a = 1, b = 5 , c = 3;
	lst =	ListCreate();
	ListPushTail(lst, &a);
	ListPushTail(lst, &b);
	ListPushTail(lst, &c);
	ListPushHead(lst, &c);
	ListPushHead(lst, &c);
	ListPopTail(lst, (void*)&ptr);
	if(	ListSize(lst)  == 4)
	 {
	 	printf(" test Size -PASS\n");
	 }else
	 {
	 	printf(" test Size -FAIL\n");
	 }
	ListDestroy(&lst , NULL);
}

/***********************************************************************************/

void TestPopTailUnderflow()
{
	List * lst;
	int *ptr;
	int a = 1, b = 5 , c = 3;
	lst =	ListCreate();
	if(	ListPopTail(lst, NULL) ==  LIST_UNDERFLOW_ERROR)
	 {
	 	printf(" test Pop Tail Underflow -PASS\n");
	 }else
	 {
	 	printf(" test Pop Tail Underflow -FAIL\n");
	 }
	ListDestroy(&lst , NULL);
}


void TestPopTailItemNull()
{
	List * lst;
	int *ptr;
	int a = 1, b = 5 , c = 3;
	lst =	ListCreate();
	ListPushTail(lst, &a);
	ListPushTail(lst, &b);
	ListPushTail(lst, &c);
	
	if(	ListPopTail(lst, NULL) ==  LIST_NULL_ELEMENT_ERROR)
	 {
	 	printf(" test Pop Tail item NULL-PASS\n");
	 }else
	 {
	 	printf(" test Pop Tail item NULL -FAIL\n");
	 }
	ListDestroy(&lst , NULL);
}

void TestPopTailListNull()
{
	List * lst;
	int *ptr;
	int a = 1, b = 5 , c = 3;
	lst =	ListCreate();
	ListPushTail(lst, &a);
	ListPushTail(lst, &b);
	ListPushTail(lst, &c);
	
	if(	ListPopTail(NULL, (void*)&ptr) ==  LIST_UNINITIALIZED_ERROR)
	 {
	 	printf(" test Pop Tail  list NULL-PASS\n");
	 }else
	 {
	 	printf(" test Pop Tail list NULL -FAIL\n");
	 }
	ListDestroy(&lst , NULL);
}

void TestPopTail()
{
	List * lst;
	int *ptr;
	int a = 1, b = 5 , c = 3;
	lst =	ListCreate();
	ListPushTail(lst, &a);
	ListPushTail(lst, &b);
	ListPushTail(lst, &c);
	
	if(	ListPopTail(lst, (void*)&ptr) ==  LIST_SUCCESS && *ptr  == 3)
	 {
	 	printf(" test Pop Tail -PASS\n");
	 }else
	 {
	 	printf(" test Pop Tail -FAIL\n");
	 }
	ListDestroy(&lst , NULL);
}


void TestPopHeadUnderFlow()
{
	List * lst;
	int item;
	int *ptr = &item;
	int a = 1, b = 5 , c = 3;
	lst =	ListCreate();
	if(	ListPopHead(lst, (void*)&ptr)  == LIST_UNDERFLOW_ERROR)
	 {
	 	printf(" test Pop underflow -PASS\n");
	 }else
	 {
	 	printf(" test Pop underflow -FAIL\n");
	 }
	ListDestroy(&lst , NULL);
}



void TestPopHeadItemNull()
{
	List * lst;
	int item;
	int *ptr = &item;
	int a = 1, b = 5 , c = 3;
	lst =	ListCreate();
	ListPushHead(lst, &a);
	ListPushHead(lst, &b);
	ListPushHead(lst, &c);
	if(	ListPopHead(lst, NULL)  == LIST_NULL_ELEMENT_ERROR)
	 {
	 	printf(" test Pop Head Input Null -PASS\n");
	 }else
	 {
	 	printf(" test Pop Head Input Null -FAIL\n");
	 }
	ListDestroy(&lst , NULL);
}


void TestPopHeadListNull()
{
	List * lst;
	int item;
	int *ptr = &item;
	int a = 1, b = 5 , c = 3;
	lst =	ListCreate();
	ListPushHead(lst, &a);
	ListPushHead(lst, &b);
	ListPushHead(lst, &c);
	if(	ListPopHead(NULL, (void*)&ptr)  == LIST_UNINITIALIZED_ERROR)
	 {
	 	printf(" test Pop Head List Null -PASS\n");
	 }else
	 {
	 	printf(" test Pop Head List Null -FAIL\n");
	 }
	ListDestroy(&lst , NULL);
}


void TestPopHeadNormal()
{
	List * lst;
	int item;
	int *ptr = &item;
	int a = 1, b = 5 , c = 3;
	lst =	ListCreate();
	ListPushHead(lst, &a);
	ListPushHead(lst, &b);
	ListPushHead(lst, &c);
	if(	ListPopHead(lst, (void*)&ptr)  == LIST_SUCCESS)
	 {
	 	printf(" test Pop Head normal -PASS\n");
	 }else
	 {
	 	printf(" test Pop Head normal -FAIL\n");
	 }
	ListDestroy(&lst , NULL);
}



void TestPopHead()
{
	List * lst;
	int item;
	int *ptr = &item;
	int a = 1, b = 5 , c = 3;
	lst =	ListCreate();
	ListPushHead(lst, &a);
	ListPushHead(lst, &b);
	ListPushHead(lst, &c);
	ListPopHead(lst, (void*)&ptr);
	if(	*ptr  == 3)
	 {
	 	printf(" test Pop Head -PASS\n");
	 }else
	 {
	 	printf(" test Pop Head -FAIL\n");
	 }
	ListDestroy(&lst , NULL);
}


void TestPushTailItemNull()
{
	List * lst;
	int item;
	int *ptr = &item;
	int a = 1, b = 5 , c = 3;
	lst =	ListCreate();
	ListPushTail(lst, &a);
	ListPushTail(lst, &b);
	if(	ListPushTail(lst, NULL) == LIST_NULL_ELEMENT_ERROR)
	 {
	 	printf(" test Push Tail item NULL-PASS\n");
	 }else
	 {
	 	printf(" test Push Tail item NULL-FAIL\n");
	 }
	ListDestroy(&lst , NULL);
}

void TestPushTailLinstNull()
{
	List * lst;
	int item;
	int *ptr = &item;
	int a = 1, b = 5 , c = 3;
	lst =	ListCreate();
	ListPushTail(lst, &a);
	ListPushTail(lst, &b);
	if(	ListPushTail(NULL, &c) == LIST_UNINITIALIZED_ERROR)
	 {
	 	printf(" test Push Tail list NULL-PASS\n");
	 }else
	 {
	 	printf(" test Push Tail list NULL-FAIL\n");
	 }
	ListDestroy(&lst , NULL);
}


void TestPushTailNormal()
{
	List * lst;
	int item;
	int *ptr = &item;
	int a = 1, b = 5 , c = 3;
	lst =	ListCreate();
	ListPushTail(lst, &a);
	ListPushTail(lst, &b);
	ListPushTail(lst, &c);
	if(	ListPushTail(lst, &c) == LIST_SUCCESS)
	 {
	 	printf(" test Push Tail normal-PASS\n");
	 }else
	 {
	 	printf(" test Push Tail normal-FAIL\n");
	 }
	ListDestroy(&lst , NULL);
}


void TestPushTail()
{
	List * lst;
	int *ptr;
	int a = 1, b = 5 , c = 3;
	lst =	ListCreate();
	ListPushTail(lst, &a);
	ListPushTail(lst, &b);
	ListPushTail(lst, &c);
	ListPopHead(lst, (void*)&ptr);
	if(*ptr == 1)
	 {
	 	printf(" test Push Tail -PASS\n");
	 }else
	 {
	 	printf(" test Push Tail -FAIL\n");
	 }
	ListDestroy(&lst , NULL);
}

void TestPushHeadItemNull()
{
	List * lst;
	int item;
	int *ptr = &item;
	int a = 1, b = 5 , c = 3;
	lst =	ListCreate();
	if(	ListPushHead(lst, NULL) == LIST_NULL_ELEMENT_ERROR)
	 {
	 	printf(" test Push Head Item NULL-PASS\n");
	 }else
	 {
	 	printf(" test Push Head  Item NULL-FAIL\n");
	 }
	ListDestroy(&lst , NULL);
}


void TestPushHeadListNull()
{
	List * lst;
	int item;
	int *ptr = &item;
	int a = 1, b = 5 , c = 3;
	lst =	ListCreate();
	if(ListPushHead(NULL, &a) == LIST_UNINITIALIZED_ERROR)
	 {
	 	printf(" test Push Head List NULL-PASS\n");
	 }else
	 {
	 	printf(" test Push Head  List NULL-FAIL\n");
	 }
	ListDestroy(&lst , NULL);
}

void TestPushHeadNormal()
{
	List * lst;
	int item;
	int *ptr = &item;
	int a = 1, b = 5 , c = 3;
	lst =	ListCreate();
	ListPushHead(lst, &a);
	ListPushHead(lst, &b);
	if(	ListPushHead(lst, &c)  == LIST_SUCCESS)
	 {
	 	printf(" test Push Head normal-PASS\n");
	 }else
	 {
	 	printf(" test Push Head normal-FAIL\n");
	 }
	ListDestroy(&lst , NULL);
}


void TestPushHead()
{
	List * lst;
	int item;
	int *ptr = &item;
	int a = 1, b = 5 , c = 3;
	lst =	ListCreate();
	ListPushHead(lst, &a);
	ListPushHead(lst, &b);
	ListPushHead(lst, &c);
	ListPopHead(lst, (void*)&ptr);
	if(	*ptr  == 3)
	 {
	 	printf(" test Push Head -PASS\n");
	 }else
	 {
	 	printf(" test Push Head -FAIL\n");
	 }
	ListDestroy(&lst , NULL);
}


void TestCreate()
{
	List * lst;
	lst =	ListCreate();
	if(	lst != NULL)
	 {
	 	printf(" test create -PASS\n");
	 }else
	 {
	 	printf(" test create -FAIL\n");
	 }
	ListDestroy(&lst , NULL);
}



