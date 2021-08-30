# Khoa Tran
# CSE 374 Homework 5
# 05/12/2020

CC = gcc

CFLAGS = -Wall -std=c11
ifdef DEBUG
	CFLAGS += -g
endif

TARGET = t9

all: $(TARGET)

OBJS = makeNode.o makeTrie.o main.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o t9 $(OBJS)

debug: CFLAGS += -g
debug: $(TARGET)

makeNode.o: makeNode.c makeNode.h
	$(CC) $(CFLAGS) -c makeNode.c

makeTrie.o: makeTrie.c makeTrie.h makeNode.h
	$(CC) $(CFLAGS) -c makeTrie.c

main.o: main.c makeTrie.h makeNode.h
	$(CC) $(CFLAGS) -c main.c

clean:
	rm -f *.o t9
