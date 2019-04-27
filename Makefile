CXX = g++
CXXFLAGS = -O3 -Wall -std=c++11
.PHONY: clean Records Users UI install run
#Targets
all: main.o Records Users UI
	mkdir -p Release
	$(CXX) $(CXXFLAGS) main.o Users/user.o Users/user_account.o Records/record.o Records/records.o UI/UI.o -o Release/SaveNow
	cd ..

Records:
	@cd Records; make; cd ..
Users:
	@cd Users; make; cd ..
UI:
	@cd UI; make; cd ..

run: all
	cd Release; ./SaveNow
	cd ..

install: all
	mkdir -p ~/SaveNow; cp Release/SaveNow ~/SaveNow
	@echo "\n\nSaveNow is now installed to you [HOME directory]/SaveNow"
	@echo "type ~/SaveNow/SaveNow to run it"
uninstall:
	rm -rf ~/SaveNow
	@echo "\n\nSaveNow is now uninstalled"

clean:
	cd Records; make clean; cd ..
	cd Users; make clean; cd ..
	cd UI; make clean; cd ..
	rm -rf Release

#main Object file
main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@