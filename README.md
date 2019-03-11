# ENGG1340 PROJECT
Github guide:

# Basic setup

0. Open terminal, change directory to any folder you wish to place our project. (I did "cd Documents")
1. Type "git clone https://github.com/jefflaichunyin/ENGG1340PROJECT.git"
2. "cd ENGG1340PROJECT"
3. "git config credential.helper store" This will save you github password so that you don't need to enter it everytime.
4. " git config --global user.email "YOUR EMAIL HERE" "
5. " git config --global user.name "YOUR NAME HERE" "
6. "git checkout development" (we will do all the testing under the development branch and merge the development branch to the master branch when a significant function is successfully implemented)

# Everytime you wish to make new changes

1. "git pull origin development" to make you local copy synchronise with the github copy
2. Do whatever changes you wish under ENGG1340PROJECT folder, I sugguest you could try modifying the TEST file.
3. Once you have done editing, type "git add --all" followed by " git commit -m "DESCRIBE THE CHANGES YOU HAVE MADE HERE" "
4. Finally "git push origin development" to make the changes visble to me.

# Project Description
In this project, we will build a personal accounting system that can satisfy the following requirements:

1) add records of income and expenses;
2) the records should contain some basic information, like amount, date, types of income or expense (e.g. food, game,
salary, etc.), account (e.g cash, bank card, credit card, etc.);
3) the records could be deleted and edited at any time;
4) users could view their records by date, type, and account;
5) the system should provide statistical report of users’ financial state (e.g. monthly income and expenses, percentage of
food expenses, etc.);
6) the accounting system allows budget setting. When expenses reach the
budget, there should be an alert from the system
