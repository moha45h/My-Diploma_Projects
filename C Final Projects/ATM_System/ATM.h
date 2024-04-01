#ifndef ATM_H_INCLUDED
#define ATM_H_INCLUDED

char loginToSystem(void);
void PrintBalance(char accountID);
void Deposit(char accountID, int cash_amount);
void Transfer(int accountID1,int cash_value,int account_to_transfer);
char withdraw(char accountID, int cash_amount);

#endif // ATM_H_INCLUDED
