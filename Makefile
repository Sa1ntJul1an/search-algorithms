all: compile link

compile:
	g++ -c main.cpp -Isrc/include
	g++ -c cell.cpp -Isrc/include
	g++ search.cpp
	g++ searchFactory.cpp
	g++ breadthFirst.cpp
	g++ depthFirst.cpp
	
# add -mwindows at end of link to hide console
link:
	g++ main.o cell.o search.o searchFactory.o breadthFirst.o depthFirst.o -o main -Lsrc/lib -lsfml-graphics -lsfml-window -lsfml-system -lopengl32 -lfreetype -lwinmm -lgdi32 	
