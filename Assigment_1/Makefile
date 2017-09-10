CXX = g++
CXXFLAGS = -Wall -pedantic -std=c++11

Distance: distance.o
	${CXX} ${CXXFLAGS} -o Distance distance.o

distance.o: distance.cpp
	${CXX} ${CXXFLAGS} -c distance.cpp

clean:
	$(RM) Distance *.o