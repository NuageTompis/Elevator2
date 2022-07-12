demo : Main.o Person.o Elevator.o
	gcc -o demo Main.o Person.o Elevator.o -lncurses

Main.o: Main.c
	gcc -c Main.c

Person.o: Person.c
	gcc -c Person.c

Elevator.o: Elevator.c
	gcc -c Elevator.c

run : demo
	./demo

clean:
	rm -f demo *.o