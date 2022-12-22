CC= g++ -Wall -std=c++11 # compilateur + options
CCO= $(CC) -c $<
OBJECTS= Tile.o Cell.o Board.o Menu.o Bar.o Game.o Main.o # liste des objets intermédiaires
all : $(OBJECTS)
	$(CC) -o go $(OBJECTS)
Tile.o : Tile.cpp Tile.hpp
	$(CCO)
Cell.o : Cell.cpp Cell.hpp
	$(CCO)
Board.o : Board.cpp Board.hpp
	$(CCO)
Menu.o : Menu.cpp Menu.hpp
	$(CCO)
Game.o : Bar.cpp Bar.hpp
	$(CCO)
Game.o : Game.cpp Game.hpp
	$(CCO)
Main.o : Main.cpp Game.hpp Bar.o Menu.hpp Board.hpp Cell.hpp Tile.hpp
	$(CCO)
clean :
	rm -f *.o go