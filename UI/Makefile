CXX = g++
CXXFLAGS = -O3 -Wall -std=c++11
.PHONY: clean
all:	UI.o
UI.o: UI.cpp UI.h Homepage.cpp RecordEditor.cpp ui_tools.cpp Stat.cpp SearchSortRecords.cpp Settings.cpp Stat.cpp Export.cpp ../Records/record.h ../Records/records.h ../Users/user.h ../Users/user_account.h
	$(CXX) $(CXXFLAGS) -c $< -o $@
clean:
	rm *.o
