CXX = g++
CXXFLAGS = -O3 -Wall -std=c++11
all: main.o records.o ui.o report.o
	$(CXX) $(CXXFLAGS) $^ -o main
	./main
test: test.o record.o
	$(CXX) $(CXXFLAGS) $^ -o test
	./test
test.o: test.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

record.o: record.cpp record.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
records.o: records.cpp records.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
ui.o: ui.cpp ui.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

report.o: report.cpp report.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@