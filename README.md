# ENGG1340 PROJECT

# Problem statement:
Overspending has become even easier because of technology advancement. People can buy things anytime and anywhere (online or in the real world). In extreme case, overspending can affect one's quality of life if they borrow personel loan. We, especially the impulsive buyers, need a clear way to record, manage and analyze our income/expense so that we can avoid from overspending, and more importantly, develop a healthy spending habit. 

# Problem setting: 
We will design a program for a family that consist of 3-5 members to use. Each member will take turns to input the details of their every day transaction. A report for each user and the whole family will be generated monthly. Since the program is designed for household use, it should run smoothly on a 4GB RAM personal computer with limited computing resources.

# Functional specifications:
Importance: 1> ... >7

Our program should statisfy the following requirement:;
1) add records of income and expenses;
2) the records should contain some basic information, like amount, date, type(income/expense), the category of income or expense (e.g. food, game,
salary, etc.), account (e.g cash, bank card, credit card, etc.);
3) the records could be deleted and edited at any time;
4) users could view/search/sort their records by date, type, account...;
5) the system should provide statistical report of users’ (as well as the whole family) financial state (e.g. monthly income and expenses, percentage of
food expenses, etc.);
6) the accounting system allows budget setting. When expenses reach the
budget, there should be an alert from the system
7) predict future income, expense and capital according to current records
8) create/remove user account, basic identity verification and allow users to change their password
9) if we have enough time we will make a pretty UI by using C++ to write a CGI scipt and support multiple users using it

# Non-functional specifications:
1. Able to record all the transaction made by a person in his entire life. Suppose that person makes 10 transactions per day, the total number of records will be 10*365*85(life expectancy in HK)= about 310,000 records
2. Sort/search records of a person within 5 seconds
3. Allows at least 5 users (number of people in a typical family) to use

# Project structure
    .
    ├── main.cpp      # program entry point, program initialization
    ├── record.cpp    # define "record" object that stores details of each transaction
    ├── records.cpp   # provide an interface to manipulate the records of an user, read/write records from/to disk
    ├── ui.cpp        # user interface + program logic
    ├── report.cpp    # generate report and store to a file
    ├── user.cpp      # user management functions (e.g. create & remove user account + update password)
    ├── demo.cpp      # demonstrate the usage of different modules
    └── README.md
    
# Basic setup

0. Open terminal, change directory to any folder you wish to place our project. (I did "cd Documents")
1. Type "git clone https://github.com/jefflaichunyin/ENGG1340-Group100.git"
2. "cd ENGG1340PROJECT"
3. "git config credential.helper store" This will save you github password so that you don't need to enter it everytime.
4. " git config --global user.email "YOUR EMAIL HERE" "
5. " git config --global user.name "YOUR NAME HERE" "
6. "git checkout development" (we will do all the testing under the development branch and merge the development branch to the master branch when a significant function is successfully implemented)

# Everytime you wish to make new changes

1. "git pull" to make you local copy synchronise with the github copy
2. Do whatever changes you wish under ENGG1340PROJECT folder, I sugguest you could try modifying the TEST file.
3. Once you have done editing, type "git add -i" followed by " git commit -m "DESCRIBE THE CHANGES YOU HAVE MADE HERE" "
4. Finally "git push" to make the changes visble to me.
