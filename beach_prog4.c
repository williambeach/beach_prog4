/* 
*
*William Beach, COP2220, Program 4, 09/11/2022
* Snack Machine Program - Simple interactive menu program with $balance
*/
#define _CRT_SECURE_NO_WARNINGS //for Visual studio compiler 
#include<stdio.h> //for printf and scanf

//variable declarations
double balance, price;
int itemNumber;

//function prototypes
void greeting(void); //greets user and explains program
void viewBalance(double balance); //displays current balance
int displayMenu(); //display menu and retrieve selection from user
double orderPrice(int itemNumber); //input item number, returns costs of item
int checkForEnoughMoney(double balance, double price); //returns true/false if balance is enough or not respectively
double reload(double balance); //reload the account balance

