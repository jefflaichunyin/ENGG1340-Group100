CXX = g++
CXXFLAGS = -O3 -Wall -std=c++11
.PHONY: clean
all:	user.o user_account.o
user.o: user.cpp user.h
	$(CXX) $(CXXFLAGS) -c $< -o $@
user_account.o: user_account.cpp user_account.h
	$(CXX) $(CXXFLAGS) -c $< -o $@
clean:
	rm *.o
