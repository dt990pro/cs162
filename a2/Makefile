run: main.o deck.o card.o hand.o dealer.o player.o game.o
	g++ main.o deck.o card.o hand.o dealer.o player.o game.o -o run
main.o: main.cpp
	g++ main.cpp -c
deck.o: deck.cpp
	g++ deck.cpp -c
card.o: card.cpp
	g++ card.cpp -c
hand.o: hand.cpp
	g++ hand.cpp -c
dealer.o: dealer.cpp
	g++ dealer.cpp -c
player.o: player.cpp
	g++ player.cpp -c
game.o: game.cpp
	g++ game.cpp -c
clean:
	rm -f a.out *.o run
