# ENGG1340 PROJECT ( SaveNow )

## Problem statement:
Overspending has become even easier because of technology advancement. People can buy things anytime and anywhere (online or in the real world). In extreme case, overspending can affect one's quality of life if they borrow loan. Although we could mark our income and outcome statement on the paper, it will be quite tedious process for us to extract useful information and grouping informations from it (e.g. figure out where do we spend most of our money)  and end up giving up easily. Also, people oftenly fail to meet their savings goal because they always find themselves an excuse to overspend (e.g. I will spend less next month but not this month because blah blah...). Therefore, in this project we are developing an easy way to record, manage and analyze our income/expense and we hope we could help our users to make informed decision before they buy and acheive their savings goal.
## Problem setting: 
*SaveNow* is a console personal accounting program designed for a family that consist of 3-5 members to use. Each family member will take turns to input the details of their every day transaction. They can set a savings goal for themselves and our program will calculate monthly spending quota in order to help them to achieve their saving goals. A report for each user and the whole family will be generated monthly. The user can have an overview of their spending easily and adjust their spending habits in order to meet the monthly quota. Eventually, the users can avoid overspending and achieve their savings goal.
## Program features:
Our program should implement the following program features:
1. add records of income and expenses
2. the records could be deleted and edited
3. users could view/search/sort their records by date, type, account...
4. provide statistical report for the users
5. allow users to set a savings goal, calculate monthly spending quota for the users and warn the user if they exceed the quota
6. predict future income, expense and capital using past records
7. create/remove user account, basic identity verification (+ simple encryption if possible) and allow users to change their password
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
### UNINSTALL
```
make uninstall
```

## Data structure:
We use xxx.dat to store user's records which "xxx" is the user name. A xxx.dat file will be created after user creates account in the programme. If user delete their account permanently in the programme, the xxx.dat file will be deleted too.
We store the user login information and user records in binary format instead of plain text format because it doesn't extra conversion step and prevent user from peeking other users password easily.

### Records
"Records" is used to manage a collection of records of an user.
##### Class
```

```
##### Example
```

```

### Record
"Record" is used to store details of a single transaction.
##### Class
```

```
##### Example
```

```


## Modules:
### Login or create account
User can choose either login to existing account or create a new account.
If the user creates a new account, he/she has to input the username once and password twice for validation.
The system will actomatically check if the account can be created successfully.

### Modify user record
This module allow user to add, edit or delete record. The records will be stored 

### Sort and search records
This module allow user to sort or search records by the following field,
1. Date
2. Amount
3. Category
4. Account
5. ID
6. Type
7. Remark

Records can be sorted by ascending order or descending order.

Records can be searched by keyword. All the records with keyword matched in the selected field will be shown.

### Manage user account
The module allow user to change password, show monthly report, set saving budget and delete user account. 


### Get income expense statistics
The module allow user to get income and expense statistics. User can input the target category and get the percentage.
##### Example
````
Category: food
food / Monthly total income : 30.00%
````
