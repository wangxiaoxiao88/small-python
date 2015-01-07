CC= g++
all : small-python

small-python: intobject.o stringobject.o dictobject.o
	$(CC) -o small-python small-python.c intobject.o stringobject.o dictobject.o
	rm -f small-python.o intobject.o stringobject.o dictobject.o

intobject.o:intobject.c  
	$(CC) -o intobject.o  -c intobject.c

stringobject.o:stringobject.c 
	$(CC) -o stringobject.o  -c stringobject.c

dictobject.o:dictobject.c 
	$(CC) -o dictobject.o  -c dictobject.c

