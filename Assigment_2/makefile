CXX = g++
CXXFLAGS = -Wall -pedantic -std=c++11

SpinOut: spinout.o main.o
	${CXX} ${CXXFLAGS} -o SpinOut spinout.o main.o

spinout.o: spinout.cpp
	${CXX} ${CXXFLAGS} -c spinout.cpp

main.o: main.cpp
	${CXX} ${CXXFLAGS} -c main.cpp

clean:
	$(RM) Spinout *.o
