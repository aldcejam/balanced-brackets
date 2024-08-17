PROG = run
CC = g++
CPPFLAGS = -O0 -g -std=c++11 -Wall -pedantic
OBJS = main.o stack.o

$(PROG): $(OBJS)
	$(CC) -o $(PROG) $(OBJS)

main.o: main.cpp
	$(CC) $(CPPFLAGS) -c main.cpp

stack.o: stack/stack.cpp stack/stack.h
	$(CC) $(CPPFLAGS) -c stack/stack.cpp

clean:
	rm -f $(PROG) $(OBJS)
