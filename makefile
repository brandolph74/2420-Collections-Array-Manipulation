EXE = bin/CollectionTest
CC = g++
OPTIONS = -std=c++11
DEBUG = -g
MEMCHECK = valgrind --tool=memcheck --leak-check=yes --show-reachable=yes

all:$(EXE)
.PHONY: all run test memcheck clean

run:$(EXE)
	@echo "Press enter to run the test driver"
	@read DUMMY
	@-$(EXE)
	@echo "Press enter to memcheck the test driver"
	@read DUMMY
	$(MEMCHECK) $(EXE)

test: $(EXE)
	$(EXE)

memcheck: $(EXE)
	$(MEMCHECK) $(EXE)

clean:
	mkdir -p obj
	mkdir -p bin
	rm obj/*
	rm bin/*
	rmdir obj
	rmdir bin

$(EXE):obj/CollectionTest.o obj/Collection.o obj/SortedCollection.o
	mkdir -p bin
	$(CC) $(OPTIONS) $(DEBUG) -o $(EXE) obj/CollectionTest.o obj/Collection.o obj/SortedCollection.o

obj/CollectionTest.o:src/CollectionTest.cpp inc/Collection.h inc/SortedCollection.h
	mkdir -p obj
	$(CC) $(OPTIONS) $(DEBUG) -o obj/CollectionTest.o -c  -I inc/ src/CollectionTest.cpp

obj/Collection.o:src/Collection.cpp inc/Collection.h
	mkdir -p obj
	$(CC) $(OPTIONS) $(DEBUG) -o obj/Collection.o -c  -I inc/ src/Collection.cpp

obj/SortedCollection.o:src/SortedCollection.cpp inc/SortedCollection.h inc/Collection.h
	mkdir -p obj
	$(CC) $(OPTIONS) $(DEBUG) -o obj/SortedCollection.o -c  -I inc/ src/SortedCollection.cpp
