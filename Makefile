all: sudoku_play

sudoku_play: alphanum.cpp grid.cpp play.cpp
	g++ play.cpp -o sudoku_play

clean: *.o
	rm *.o

