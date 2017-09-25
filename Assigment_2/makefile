CXX = g++
CXXFLAGS = -Wall -pedantic -std=c++11

Spinout: spinout.o main.o
	${CXX} ${CXXFLAGS} -o Spinout spinout.o main.o

spinout.o: spinout.cpp
	${CXX} ${CXXFLAGS} -c spinout.cpp

main.o: main.cpp
	${CXX} ${CXXFLAGS} -c main.cpp

clean:
	$(RM) Spinout *.o