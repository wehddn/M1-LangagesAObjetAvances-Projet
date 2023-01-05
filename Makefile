# compilateur + options
CC= g++ -Wall -std=c++11
CCO= $(CC) -c $<

# liste des objets intermédiaires
OBJECTS = Tile.o TileDomino.o TileTrax.o TileCarcassonne.o \
			Cell.o CellTrax.o CellDomino.o CellCarcassonne.o \
			Board.o BoardDomino.o BoardTrax.o BoardCarcassonne.o \
			Bar.o BarDomino.o BarTrax.o BarCarcassonne.o \
			Player.o PlayerDomino.o PlayerTrax.o PlayerCarcassonne.o \
			Game.o GameDomino.o GameTrax.o GameCarcassonne.o \
			GarbageCollector.o Menu.o Main.o

all : $(OBJECTS)
	$(CC) $(OBJECTS) -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system

Tile.o : Tile.cpp Tile.hpp
	$(CCO)
TileDomino.o : TileDomino.cpp Tile.hpp
	$(CCO)
TileTrax.o : TileTrax.cpp Tile.hpp
	$(CCO)
TileCarcassonne.o : TileCarcassonne.cpp Tile.hpp
	$(CCO)
Cell.o : Cell.cpp Cell.hpp
	$(CCO)
CellDomino.o : CellDomino.cpp Cell.hpp
	$(CCO)
CellTrax.o : CellTrax.cpp Cell.hpp
	$(CCO)
CellCarcassonne.o : CellCarcassonne.cpp Cell.hpp
	$(CCO)
Board.o : Board.cpp Board.hpp
	$(CCO)
BoardDomino.o : BoardDomino.cpp Board.hpp
	$(CCO)
BoardTrax.o : BoardTrax.cpp Board.hpp
	$(CCO)
BoardCarcassonne.o : BoardCarcassonne.cpp Board.hpp
	$(CCO)
Menu.o : Menu.cpp Menu.hpp
	$(CCO)
Bar.o : Bar.cpp Bar.hpp
	$(CCO)
BarTrax.o : BarTrax.cpp Bar.hpp
	$(CCO)
BarDomino.o : BarDomino.cpp Bar.hpp
	$(CCO)
BarCarcassonne.o : BarCarcassonne.cpp Bar.hpp
	$(CCO)
Player.o : Player.cpp Player.hpp
	$(CCO)
PlayerTrax.o : PlayerTrax.cpp Player.hpp
	$(CCO)
PlayerDomino.o : PlayerDomino.cpp Player.hpp
	$(CCO)
PlayerCarcassonne.o : PlayerCarcassonne.cpp Player.hpp
	$(CCO)
Game.o : Game.cpp Game.hpp
	$(CCO)
GameDomino.o : GameDomino.cpp Game.hpp
	$(CCO)
GameTrax.o : GameTrax.cpp Game.hpp
	$(CCO)
GameCarcassonne.o : GameCarcassonne.cpp Game.hpp
	$(CCO)
GarbageCollector.o : GarbageCollector.cpp GarbageCollector.hpp
	$(CCO)

clean :
	rm -f *.o sfml-app