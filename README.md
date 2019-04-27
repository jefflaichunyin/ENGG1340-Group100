# ENGG1340 PROJECT ( SaveNow )

## Problem statement:
Overspending has become even easier because of technology advancement. People can buy things anytime and anywhere (online or in the real world). In extreme case, overspending can affect one's quality of life if they borrow loan. Although we could mark our income and outcome statement on the paper, it will be quite tedious process for us to extract useful information and grouping informations from it (e.g. figure out where do we spend most of our money)  and end up giving up easily. Also, people oftenly fail to meet their savings goal because they always find themselves an excuse to overspend (e.g. I will spend less next month but not this month because blah blah...). Therefore, in this project we are developing an easy way to record, manage and analyze our income/expense and we hope we could help our users to make informed decision before they buy and acheive their savings goal.
## Problem setting: 
*SaveNow* is a console personal accounting program designed for a family that consist of 3-5 members to use. Each family member will take turns to input the details of their every day transaction. They can set a savings goal for themselves and our program will calculate monthly saving goal and spending quota for them in order to help them to achieve their saving goals. The user can have an overview of their spending easily and adjust their spending habits in order to meet the monthly quota. Eventually, the users can avoid overspending and achieve their savings goal.
## Program features:
We have implemented the following program features:
1. add records of transaction (income/expense/transfer)
2. delete and edit records
3. users could view/search/sort their records by date, type, account...
4. provide a visualized statistical report for the users
5. allow users to set a savings goal, calculate monthly spending quota for the users and warn the user if they exceed the quota
6. create/remove user account, basic identity verification and allow users to change their password
7. use presence/range/type/length check to validate every user input
8. allow user to navigate between pages of records instead of scrolling
9. allow user to export record to csv file
## User Manual:
=======

## How to use:

### INSTALL
```
make
make install
```
### RUN
```
~/SaveNow/SaveNow
```
You can also run SaveNow without installing by
```
make run
```
### UNINSTALL
```
make uninstall
```
## Screenshots

### Create User Account
![Screenshot from 2019-04-27 17-52-52](https://user-images.githubusercontent.com/15307683/56848302-c616e980-6919-11e9-9181-36d6989319d3.png)

In the first run, please press 2 to create a new user

![Screenshot from 2019-04-27 17-52-52](https://user-images.githubusercontent.com/15307683/56848302-c616e980-6919-11e9-9181-36d6989319d3.png)

After logging  in, this page will be displayed. User might need to adjust the windows size.

### Add Record
![Screenshot from 2019-04-27 17-54-45](https://user-images.githubusercontent.com/15307683/56848341-4fc6b700-691a-11e9-8760-ca9441b54e69.png)

The user can give details like type/amount/category and remark of the transaction to create new record

![Screenshot from 2019-04-27 17-54-49](https://user-images.githubusercontent.com/15307683/56848354-843a7300-691a-11e9-8ad8-2db1b6df7e2c.png)

![Screenshot from 2019-04-27 17-55-26](https://user-images.githubusercontent.com/15307683/56848360-a7652280-691a-11e9-866c-b3d88125562c.png)

The user could transfer money from one of his account to another account, such transaction will be record in two records

![Screenshot from 2019-04-27 17-56-41](https://user-images.githubusercontent.com/15307683/56848379-e09d9280-691a-11e9-8153-5e8d076e99dd.png)

### Edit Record
![Screenshot from 2019-04-27 17-56-41](https://user-images.githubusercontent.com/15307683/56848418-573a9000-691b-11e9-91bf-376dc33a353e.png)

Records can be edited by re-entering the details again

### Delete Record
![Screenshot from 2019-04-27 17-58-05](https://user-images.githubusercontent.com/15307683/56848429-79341280-691b-11e9-903f-95fb06ff4fc3.png)

User can delete the record by giving the record ID

### Search Record
![Screenshot from 2019-04-27 18-05-36](https://user-images.githubusercontent.com/15307683/56848443-a4b6fd00-691b-11e9-888d-1bd382e1204c.png)

![Screenshot from 2019-04-27 18-05-40](https://user-images.githubusercontent.com/15307683/56848445-af719200-691b-11e9-953d-4ba0bb71bc98.png)

User can enter a keyword to search the records, all revelent records will be displayed 

### Sort Record
![Screenshot from 2019-04-27 18-09-57](https://user-images.githubusercontent.com/15307683/56848460-f495c400-691b-11e9-8c7e-36824adadbdf.png)

User can sort the records by giving the key field and sorting order

### Set Saving Goal
![Screenshot from 2019-04-27 18-11-28](https://user-images.githubusercontent.com/15307683/56848478-29098000-691c-11e9-829e-44a179102093.png)
![Screenshot from 2019-04-27 18-12-44](https://user-images.githubusercontent.com/15307683/56848479-29098000-691c-11e9-9ea5-1848ef28df12.png)

User can set a saving goal in the setting menu, monthly saving goal and monthly quota is calculated automatically. Negative quota mean the user have overspended. The saving progress can be visualized 

![Screenshot from 2019-04-27 18-18-18](https://user-images.githubusercontent.com/15307683/56848495-6bcb5800-691c-11e9-93d6-94045abb94f1.png)

A congratulation message will be displayed if the user can achieve his saving goal

### View Statistics
![Screenshot from 2019-04-27 18-46-33](https://user-images.githubusercontent.com/15307683/56848522-cfee1c00-691c-11e9-8728-8177e97c4896.png)

The user could use the statistic function to visualize his spending habits

### Export to csv file
![Screenshot from 2019-04-27 10-03-02](https://user-images.githubusercontent.com/47233421/56850758-3bde7d80-6939-11e9-81a2-700f3a38c9b7.png)
![Screenshot from 2019-04-27 10-02-44](https://user-images.githubusercontent.com/47233421/56850747-1ea9af00-6939-11e9-93a2-51a9c6931da0.png)
![Screenshot from 2019-04-27 9-56-33](https://user-images.githubusercontent.com/47233421/56850752-2cf7cb00-6939-11e9-9196-1ed2b864f874.png)

### Input Validation
![Screenshot from 2019-04-27 18-50-29](https://user-images.githubusercontent.com/15307683/56848579-63275180-691d-11e9-8665-daaaa0b22adc.png)

Range check, presence check and type check will be carry out on every numerical input

![Screenshot from 2019-04-27 18-53-15](https://user-images.githubusercontent.com/15307683/56848618-bd281700-691d-11e9-993d-fc1c6f1a07b0.png)
Password input will be validated by length check and presence check

![Screenshot from 2019-04-27 18-54-43](https://user-images.githubusercontent.com/15307683/56848641-f6608700-691d-11e9-992f-af2e922a4ac6.png)

User existance will be checked before creating, so that the user record will not be overwritten

![Screenshot from 2019-04-27 18-57-26](https://user-images.githubusercontent.com/15307683/56848683-522b1000-691e-11e9-83f2-7dc7c39db3a6.png)

User must enter a postive saving goal and set a valid deadline 


