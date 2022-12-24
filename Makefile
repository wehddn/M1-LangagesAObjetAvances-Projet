CC= g++ -Wall -std=c++11 # compilateur + options
CCO= $(CC) -c $<
OBJECTS= Tile.o TileDomino.o TileTrax.o Cell.o Board.o BoardTrax.o Menu.o Bar.o Player.o Game.o GameDomino.o GameTrax.o Main.o # liste des objets intermédiaires
all : $(OBJECTS)
	$(CC) -o go $(OBJECTS)
Tile.o : Tile.cpp Tile.hpp
	$(CCO)
TileDomino.o : TileDomino.cpp Tile.hpp
	$(CCO)
TileTrax.o : TileTrax.cpp Tile.hpp
	$(CCO)
Cell.o : Cell.cpp Cell.hpp
	$(CCO)
Board.o : Board.cpp Board.hpp
	$(CCO)
BoardTrax.o : BoardTrax.cpp BoardTrax.hpp
	$(CCO)
Menu.o : Menu.cpp Menu.hpp
	$(CCO)
Bar.o : Bar.cpp Bar.hpp
	$(CCO)
Player.o : Player.cpp Player.hpp
	$(CCO)
Game.o : Game.cpp Game.hpp
	$(CCO)
GameDomino.o : GameDomino.cpp Game.hpp
	$(CCO)
GameTrax.o : GameTrax.cpp Game.hpp
	$(CCO)
Main.o : Main.cpp Game.hpp Player.hpp Bar.hpp Menu.hpp Board.hpp Cell.hpp Tile.hpp
	$(CCO)
clean :
	rm -f *.o go