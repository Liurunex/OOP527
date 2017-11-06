CXX = g++
CXXFLAGS = -Wall -pedantic -std=c++11 -g3 -DCS527

Game: game_main.o spinout.o conway.o
	${CXX} ${CXXFLAGS} -o $@ $^

clean:
	$(RM) Game *.o