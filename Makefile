CXX = g++
CXXFLAGS = -O3 -Wall -std=c++11
.PHONY: clean demo
#Targets
all: main.o record.o records.o ui.o report.o user.o
	$(CXX) $(CXXFLAGS) $^ -o main
	./main
demo: demo.o record.o records.o
	$(CXX) $(CXXFLAGS) $^ -o demo
	./demo
clean:
	rm *.o
#Executables	
demo.o: demo.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
#Object files
record.o: record.cpp record.h
	$(CXX) $(CXXFLAGS) -c $< -o $@
records.o: records.cpp records.h
	$(CXX) $(CXXFLAGS) -c $< -o $@
ui.o: ui.cpp ui.h
	$(CXX) $(CXXFLAGS) -c $< -o $@
report.o: report.cpp report.h
	$(CXX) $(CXXFLAGS) -c $< -o $@
user.o: user.cpp user.h
	$(CXX) $(CXXFLAGS) -c $< -o $@