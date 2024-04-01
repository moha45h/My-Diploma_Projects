#include <stdio.h>
#include <stdlib.h>
#include"ATM.h"
#include<stdint.h>
int main()
{
   char authentication=0;
  authentication= loginToSystem();//x
     //Transfer(11,3500,22);
     // Deposit(22,1400);
     // PrintBalance(22);//x
    printf("%d\n" ,authentication);


  // withdraw(11,2000);
    return 0;
}
