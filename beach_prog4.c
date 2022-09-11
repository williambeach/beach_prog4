/* 
*
*William Beach, COP2220, Program 4, 09/11/2022
* Traveling Vendor Program - Simple interactive menu program with $balance view and deposit
*/
#define _CRT_SECURE_NO_WARNINGS //for Visual studio compiler 
#include<stdio.h> //for printf and scanf

//variable declarations
double balance = 5.00; //initialized balance to a starting dollar amount
double price, deposit;
int itemNumber = 1; //initalized itemNumber with consideration to do..while loop execution

//function prototypes
void greeting(void); //greets user and explains program
void viewBalance(double balance); //displays current balance
int displayMenu(); //display menu and retrieve selection from user
double orderPrice(int itemNumber); //input item number, returns costs of item
double checkForEnoughMoney(double balance, double price); //returns true/false if balance is enough or not respectively
double reload(double balance); //reload the account balance

int main() {
    greeting();
    viewBalance(balance);
    while ( itemNumber != 9 ) {
        itemNumber = displayMenu();
        if (itemNumber == 9) {
            break;
        }
        price = orderPrice(itemNumber);
        balance = checkForEnoughMoney(balance, price);
        reload(balance);
    }
    printf("Thank you for shopping with us fat cats...Have a nice day.\n");
    return 0;
}

void greeting(void) {
    printf(" _______________________________________________________________________________ \n");
    printf("|                                                                               |\n");
    printf("|-------------------------------------------------------------------------------|\n");
    printf("|........Welcome traveler, to Khajiit's Traveling Wares and Certain Fares.......|\n");
    printf("|......................Khajiit has wares if you have coin.......................|\n");
    printf("|...I present to you a selection of our finest products from around the world...|\n");
    printf("|-------------------------------------------------------------------------------|\n");
    printf("|_______________________________________________________________________________|\n\n");
}

void viewBalance(double balance) {
    printf(" _______________________________________________________________________________\n");
    printf("|                                                                               |\n");
    printf("|                              Account Balance: $%.2f                           |\n", balance);
    printf("|_______________________________________________________________________________|\n\n");
}


int displayMenu() {
    do{
        if (!(itemNumber >= 1 && itemNumber <=9)) {
            printf("Please enter a valid selection\n");
        }
        printf(" _______________________________________________________________________________\n");
        printf("|                                                                               |\n");
        printf("|                                      MENU                                     |\n");
        printf("|                                                                               |\n");
        printf("|                         (1)  Cat's Eye Prism     $3.00                        |\n");
        printf("|                         (2)  Corpse of Mayhem    $5.00                        |\n");
        printf("|                         (3)  Guardian Mane       $1.00                        |\n");
        printf("|                         (4)  Full Moons Tile     $4.00                        |\n");
        printf("|                         (5)  Khajiit Cat Bed     $3.00                        |\n");
        printf("|                         (6)  Waning Moons Tile   $3.00                        |\n");
        printf("|                         (7)  Treasure Chest      $5.00                        |\n");
        printf("|                         (8)  Check Balance       FREE                         |\n");
        printf("|                         (9)  Exit Shoppe         FREE                         |\n");
        printf("|                                                                               |\n");
        printf("|                                                                               |\n");
        printf("|_______________Please Enter Your Selection (1-9) and Press Enter:______________|\n\n");
        scanf("%d", &itemNumber);
        printf("\n");
    } while(!(itemNumber >= 1 && itemNumber <=9)); {
        return itemNumber;
    }
}

double orderPrice(int itemNumber) {
    switch (itemNumber) {
        case 1:
            printf(" ______________________________________________\n");
            printf("|                                              |\n");
            printf("|   The cost of the Cat's Eye Prism is $3.00   |\n");
            printf("|______________________________________________|\n");
            price = 3.00;
            return price;
        case 2:
            printf(" ______________________________________________\n");
            printf("|                                              |\n");
            printf("|  The cost of the Corpse of Mayhem is $5.00   |\n");
            printf("|______________________________________________|\n");
            price = 5.00;
            return price;
        case 3:
            printf(" ______________________________________________\n");
            printf("|                                              |\n");
            printf("|    The cost of the Guardian Mane is $1.00    |\n");
            printf("|______________________________________________|\n"); 
            price = 1.00;
            return price;
        case 4:
            printf(" ______________________________________________\n");
            printf("|                                              |\n");
            printf("|   The cost of the Full Moons Tile is $4.00   |\n");
            printf("|______________________________________________|\n"); 
            price = 4.00;
            return price;
        case 5:
            printf(" ______________________________________________\n");
            printf("|                                              |\n");
            printf("|   The cost of the Khajiit Cat Bed is $3.00   |\n");
            printf("|______________________________________________|\n");
            price = 3.00;
            return price;
        case 6:
            printf(" ______________________________________________\n");
            printf("|                                              |\n");
            printf("|  The cost of the Waning Moons Tile is $3.00  |\n");
            printf("|______________________________________________|\n");
            price = 3.00;
            return price;
        case 7:
            printf(" ______________________________________________\n");
            printf("|                                              |\n");
            printf("|   The cost of the Treasure Chest is $5.00    |\n");
            printf("|______________________________________________|\n");
            price = 5.00;
            return price;
        case 8:
            viewBalance(balance);
            return 0.00;
    }
}
    
double checkForEnoughMoney(double balance, double price) {
    if ((balance - price) < 0) {
        printf(" ______________________________________________\n");
        printf("|                                              |\n");
        printf("|       Sorry, you don't have enough coin      |\n");
        printf("|______________________________________________|\n");
    }
    else {
        balance = balance - price;
        printf(" ______________________________________________\n");
        printf("|                                              |\n");
        printf("|         Thank you for your purchase!         |\n");
        printf("|                                              |\n");
        printf("|           Your new balance is: $%.2f         |\n", balance);
        printf("|______________________________________________|\n");
    }
    return balance;
}

double reload(double balance) {
    printf(" ______________________________________________\n");
    printf("|                                              |\n");
    printf("|        Your current balance is: $%.2f        |\n", balance);
    printf("|                                              |\n");
    printf("|       Please enter your deposit amount       |\n");
    printf("|______________________________________________|\n");
    scanf("%lf", &deposit);
    balance = balance + deposit;
    printf(" ______________________________________________\n");
    printf("|                                              |\n");
    printf("|          Your new balance is: $%.2f          |\n", balance);
    printf("|                                              |\n");
    printf("|______________________________________________|\n");
    return balance;
}