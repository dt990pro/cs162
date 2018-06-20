run: main.o animal.o zoo.o tiger.o pbear.o penguin.o new_animal.o
	g++ main.o animal.o zoo.o tiger.o pbear.o penguin.o new_animal.o -o run
main.o: main.cpp
	g++ main.cpp -c
animal.o: animal.cpp
	g++ animal.cpp -c
zoo.o: zoo.cpp
	g++ zoo.cpp -c
tiger.o: tiger.cpp
	g++ tiger.cpp -c
pbear.o: pbear.cpp
	g++ pbear.cpp -c
penguin.o: penguin.cpp
	g++ penguin.cpp -c
new_animal.o: new_animal.cpp
	g++ new_animal.cpp -c
clean:
	rm -f a.out *.o run
