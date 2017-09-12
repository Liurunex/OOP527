CXX = g++
CXXFLAGS = -Wall -pedantic -std=c++11

Spinout: spinout.o
	${CXX} ${CXXFLAGS} -o Spinout spinout.o

spinout.o: spinout.cpp
	${CXX} ${CXXFLAGS} -c spinout.cpp

clean:
	$(RM) Spinout *.o