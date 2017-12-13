CXX=g++
CXXFLAGS=-Wall -pedantic -std=c++11 -g3

Fission: checkers.o fissionboard.o fissionpiece.o fissionpiecelight.o math.o board.o piece.o
	${CXX} -o $@ ${CXXFLAGS} $^

clean:
	$(RM) Fission *.o