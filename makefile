TARGET= genItr.out
CC= gcc
CFLAGS= -ansi -g -pedantic 
OBJS= ListItr.o ListItrTest.o genericDLL.o GeneralList.o 

$(TARGET): $(OBJS)
	$(CC) -o $(TARGET) $(OBJS)
	
ListItr.o:  ListInternal.h ListItr.h  ListItr.c
	$(CC) $(CFLAGS) -c ListItr.c
	
ListItrTest.o: ListItrTest.c  ListInternal.h ListItr.h genericDLL.h
	$(CC) $(CFLAGS) -c ListItrTest.c
	
genericDLL.o:genericDLL.h genericDLL.c
	$(CC) $(CFLAGS) -c genericDLL.c	

GeneralList.o: GeneralList.c  ListInternal.h ListItr.h genericDLL.h GeneralList.h
	$(CC) $(CFLAGS) -c GeneralList.c	
	
	
clean:
	rm -f $(TARGET) $(OBJS)

