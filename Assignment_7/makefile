CXX=g++
CXXFLAGS=-Wall -pedantic -std=c++11 -g3

Checkers: checkers.o checkerboard.o checker.o king.o math.o board.o piece.o
	${CXX} -o $@ ${CXXFLAGS} $^

clean:
	$(RM) Checkers *.o