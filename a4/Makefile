run: main.o wumpus.o pit.o gold.o bat.o event.o room.o
	g++ main.o wumpus.o pit.o gold.o bat.o event.o room.o -o run
main.o: main.cpp
	g++ main.cpp -c
wumpus.o: wumpus.cpp
	g++ wumpus.cpp -c
pit.o: pit.cpp
	g++ pit.cpp -c
gold.o: gold.cpp
	g++ gold.cpp -c
bat.o: bat.cpp
	g++ bat.cpp -c
event.o: event.cpp
	g++ event.cpp -c
room.o: room.cpp
	g++ room.cpp -c
clean:
	rm -f a.out *.o run
