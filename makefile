#Automatic compilation using make
#Just type in terminal 'make' and this will compile it for you

CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99 -Wfloat-equal     #compiler flags 
LIBS = -lm                                                  #adding required libraries

all: functions.o main.o
	$(CC) $(FLAGS) functions.o main.o -o rpnCalculator $(LIBS)
	rm -f *.o

functions.o: functions.c functions.h
	$(CC) $(FLAGS) functions.c -c -o functions.o $(LIBS)

main.o: main.c functions.h
	$(CC) $(FLAGS) main.c -c -o main.o $(LIBS)

clean:
	rm -f rpnCalculator         					 #command 'make clean' will delete compiled executable program

