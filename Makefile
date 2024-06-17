SOURCES = ./src/main.cpp ./src/grid.cpp ./src/game.cpp  ./src/utils.cpp

default:
	g++ $(SOURCES) -o ./build/game.exe -g -O1 -Wall -Wno-missing-braces -I include/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm 
	./build/game.exe