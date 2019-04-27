CXX = g++
CXXFLAGS = -O3 -Wall -std=c++11
.PHONY: clean
all:	record.o records.o
record.o: record.cpp record.h
	$(CXX) $(CXXFLAGS) -c $< -o $@
records.o: records.cpp records.h
	$(CXX) $(CXXFLAGS) -c $< -o $@
clean:
	rm *.o
