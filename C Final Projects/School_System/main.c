#include <stdio.h>
#include <stdlib.h>
#include<stdint-gcc.h>
#include"School.h"

int main()
{
    uint8_t num=0;
    //SDB_IsFULL();
   // num=SDB_GetUsedSize();

  SDB_AddEntry(0,2024,14,50);
  //SDB_DeleteEntry(15);
//    SDB_ReadEntry(25,14,&student);
   SDB_IsIdExist(5);
   // printf("%d",num);
    return 0;
}
