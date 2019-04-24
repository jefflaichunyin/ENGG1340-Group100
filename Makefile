CXX = g++
CXXFLAGS = -O3 -Wall -std=c++11
.PHONY: clean demo
#Targets
all: main.o record.o records.o ui.o report.o user.o user_account.o
	mkdir -p Release
	$(CXX) $(CXXFLAGS) $^ -o Release/SaveNow
	cd Release;./SaveNow
	cd ..
demo: demo.o record.o records.o user.o user_account.o
	$(CXX) $(CXXFLAGS) $^ -o demo
	./demo
clean:
	rm *.o
	rm -rf Release
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
ui.o: ui.cpp ui.h RecordEditor.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
report.o: report.cpp report.h
	$(CXX) $(CXXFLAGS) -c $< -o $@
user.o: user.cpp user.h
	$(CXX) $(CXXFLAGS) -c $< -o $@
user_account.o: user_account.cpp user_account.h
	$(CXX) $(CXXFLAGS) -c $< -o $@
