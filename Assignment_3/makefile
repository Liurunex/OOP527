CXX = g++
CXXFLAGS = -Wall -pedantic -std=c++11

Conway: conway.o main.o
	${CXX} ${CXXFLAGS} -o Conway conway.o main.o

conway.o: conway.cpp
	${CXX} ${CXXFLAGS} -c conway.cpp

main.o: main.cpp
	${CXX} ${CXXFLAGS} -c main.cpp

clean:
	$(RM) Conway *.o
