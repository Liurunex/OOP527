CXX = g++
CXXFLAGS = -g -std=c++11

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $<

DISTANCE = distance.o
test: $(DISTANCE)
	$(CXX) -o $@ $(DISTANCE)

clean:
	$(RM) *.o test