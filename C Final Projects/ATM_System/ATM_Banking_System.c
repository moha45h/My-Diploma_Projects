#include <stdio.h>
#include <stdlib.h>
#include"ATM.h"
#include<stdint.h>
#include<stdbool.h>
#define CLIENTS    3
/*
Project Name : ATM Banking System
Created By : Eng.Mohamed Abd Elfattah Ali Mahfouz
Version : 1
Date : 5/2/2024
AVR Diploma D1
Phone

*/

//***********************variables*********************************************
typedef struct
{
    uint8_t Account_ID;
    uint8_t Account_Password;
}Clients;

Clients clients_database[CLIENTS]=
{
       {11,111},
       {22,222},
       {33,333}
};


typedef struct
 {
   int balance1;
   int balance2;
   int balance3;

}client_money;

client_money money[CLIENTS]={5000,6000,7000};


//*******************************************************************************
char loginToSystem(void)
{
    uint8_t ID_Number=0 ; // variable to store id number
    uint8_t Password=0;
    uint8_t i=0;
    printf("Please Enter the ID \n");
    scanf("%d",&ID_Number);
    printf("Please Enter the password \n");
    scanf("%d",&Password);

    for(i=0;i<CLIENTS;i++)
    {
       if(clients_database[i].Account_ID==ID_Number && clients_database[i].Account_Password==Password)
        {
        printf("login succeeded \n");
        return true ;
          }
    }
    printf("login failed\n");
}

void PrintBalance(char accountID)
{

    switch(accountID)
    {
    case 11:
        printf("The Balance is = %d \n ", money[0].balance1);
    break;
    case 22:
        printf("The Balance is = %d \n", money[1].balance2);
    break;
    case 33:
        printf("The Balance is = %d \n", money[2].balance3);
    break;
        default :
        printf("Please Enter Correct ID \n");
    }


}
void Deposit(char accountID, int cash_amount)//assume number of accounts is 3
{
    if(accountID==11)
    {
        money[0].balance1 +=cash_amount;
        printf("successful Operation Thank you ! \n");
        printf(" your balance is = %d \n",money[0].balance1);
    }
     else  if(accountID==22)
    {
        money[1].balance2 +=cash_amount;
        printf("successful Operation Thank you ! \n");
        printf(" your balance is = %d \n",money[1].balance2);
    }
       else  if(accountID==33)
    {
        money[2].balance3 +=cash_amount;
        printf("successful Operation Thank you ! \n");
        printf(" your balance is = %d \n",money[2].balance3);
    }
else
    printf("invalid id \n ");

}

void Transfer(int accountID1,int cash_value,int accounttotransfer)
{
int value=0;

if(accountID1==11)
{

          if(accounttotransfer==22)
          {
            value=money[0].balance1- cash_value;
            money[0].balance1=value;
            money[1].balance2 +=cash_value;
            printf("Account ID 11 Available balance is = %d \n ",money[0].balance1);
            printf("Account ID 22 you transferred money balance is = %d \n ",money[1].balance2);
          }
          else if(accounttotransfer==33)
          {
            value=money[0].balance1- cash_value;
             money[0].balance1=value;
             money[2].balance3 +=cash_value;
             printf("Account ID11 Available balance is = %d \n ",money[0].balance1);
             printf("Account ID 33 you transferred money balance is = %d \n ",money[2].balance3);
            }
            else
                printf("this account is invalid ");
 }
else if (accountID1==22){


          if(accounttotransfer==11)
          {
             value=money[1].balance2 - cash_value;
             money[1].balance2=value;  // money remainder value is stored at an array
             money[0].balance1 +=cash_value;
             printf("Account ID 22 Available balance is = %d \n ",money[1].balance2);
             printf("Account ID11 you transferred money balance is = %d \n ",money[0].balance1);
          }
          else if(accounttotransfer==33)
          {
            value=money[1].balance2- cash_value;
             money[1].balance2 =value;
             money[2].balance3 +=cash_value;
             printf("Account ID 22 Available balance is = %d \n ",money[1].balance2);
             printf("Account ID 33 you transferred money balance is = %d \n ",money[2].balance3);
          }
          else{
             printf("this account is invalid ");
          }
}
 else if (accountID1==33)
         {

              if(accounttotransfer==11)
          {
              value=money[2].balance3- cash_value;
              money[2].balance3=value;
              money[0].balance1=money[0].balance1+cash_value;
              printf("Account ID 33 Available balance is = %d \n ",money[2].balance3);
              printf("Account ID 11 you transferred money balance is = %d \n ",money[0].balance1);
          }
          else if(accounttotransfer==22)
          {
            value=money[2].balance3- cash_value;
             money[2].balance3=value;
             money[1].balance2=money[1].balance2+cash_value;
             printf("Account ID 33 Available balance is = %d \n ",money[2].balance3);
             printf("Account ID 22 you transferred money balance is = %d \n ",money[1].balance2);
           }
            }
            else
                printf("this account is invalid ");
}
char withdraw(char accountID, int cash_amount)
{
    switch(accountID)
    {
 case 11:
     money[0].balance1 -=cash_amount;
    printf("The cash Available in Account ID 11 is = %d\n", money[0].balance1);
    printf("Successful Transaction  \n");
break;
 case 22:
  money[1].balance2 -=cash_amount;
    printf("the cash Available in Account ID 22 is = %d\n",money[1].balance2);
    printf("successful Transaction \n ");
break;
 case 33:

    printf("the cash Available in Account ID 33 = %d\n",money[2].balance3);
    printf("successful Transaction  ");
break;
 default:
    printf("Please Enter correct id ");
    }

}
