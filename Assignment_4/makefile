CXX = g++
CXXFLAGS = -Wall -pedantic -std=c++11

Cooccur: main.o
	${CXX} ${CXXFLAGS} -o Cooccur main.o

main.o: main.cpp
	${CXX} ${CXXFLAGS} -c main.cpp

clean:
	$(RM) Cooccur *.o
