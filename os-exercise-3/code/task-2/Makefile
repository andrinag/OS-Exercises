# To run, enter: make all

all: diningphilosophers

diningphilosophers: main.o dining.o philosopher.o
	gcc -o diningphilosophers main.o dining.o philosopher.o -lpthread

main.o: main.c dp.h
	gcc -c main.c -lpthread

dining.o: dining.c dp.h
	gcc -c dining.c -lpthread

philosopher.o: philosopher.c dp.h
	gcc -c philosopher.c -lpthread
