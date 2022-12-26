CC= g++ -Wall -std=c++11 # compilateur + options
CCO= $(CC) -c $<
OBJECTS= Tile.o TileDomino.o TileTrax.o Cell.o CellTrax.o CellDomino.o Board.o BoardDomino.o BoardTrax.o Menu.o Bar.o BarTrax.o BarDomino.o Player.o PlayerTrax.o PlayerDomino.o Game.o GameDomino.o GameTrax.o Main.o # liste des objets intermédiaires
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
CellTrax.o : CellTrax.cpp Cell.hpp
	$(CCO)
CellDomino.o : CellDomino.cpp Cell.hpp
	$(CCO)
Board.o : Board.cpp Board.hpp
	$(CCO)
BoardDomino.o : BoardDomino.cpp Board.hpp
	$(CCO)
BoardTrax.o : BoardTrax.cpp Board.hpp
	$(CCO)
Menu.o : Menu.cpp Menu.hpp
	$(CCO)
Bar.o : Bar.cpp Bar.hpp
	$(CCO)
BarTrax.o : BarTrax.cpp Bar.hpp
	$(CCO)
BarDomino.o : BarDomino.cpp Bar.hpp
	$(CCO)
Player.o : Player.cpp Player.hpp
	$(CCO)
PlayerTrax.o : PlayerTrax.cpp Player.hpp
	$(CCO)
PlayerDomino.o : PlayerDomino.cpp Player.hpp
	$(CCO)
Game.o : Game.cpp Game.hpp
	$(CCO)
GameDomino.o : GameDomino.cpp Game.hpp
	$(CCO)
GameTrax.o : GameTrax.cpp Game.hpp
	$(CCO)
clean :
	rm -f *.o go