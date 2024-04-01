//*******************************************************************************************
/*
project name : School Database System
created by :ENG.Mohamed A.Ali
date :9/2/2024
version :1

*/


#include"School.h"
#include<stdio.h>
#include<stdint-gcc.h>
#define MAX_STUDENT_NUMBER       20
#define MAX_COURSES     5
/*1- Assume the number of students is =3
   2-students ids is :
                 student 1=11
                 student 2=22
                 student 3=33
   3-year of grade is 2024
   4-course 1 id  =111
   5-course 1 grade =50
   6-course 2 id  =222
   7-course 2 grade =55
   4-course 3 id  =333
   5-course 3 grade =60
*/
typedef struct
{
    uint8_t Student_ID[MAX_STUDENT_NUMBER];
    uint16_t Year_of_Grade;
    uint8_t Course_ID[MAX_COURSES] ;
    uint8_t Course_Grade[MAX_COURSES];


}school_system;

school_system student[3]={{11,2022,111,50},{22,2023,222,55},{33,2024,333,60}};
school_system id_list[MAX_STUDENT_NUMBER];

typedef struct
{
  uint8_t ID;
}database;

//database id_list[MAX_STUDENT_NUMBER];

/*
typedef struct
{
   uint8_t id;
   uint8_t grades[MAX_COURSES];

}School;
School  student_Database[MAX_STUDENT_NUMBER];
*/

void SDB_IsFULL(void)
{
    if(MAX_STUDENT_NUMBER==sizeof(school_system))
    {
        printf("The Database is Full \n");
    }
    else
         printf("The Database is not Full \n");

}
uint8_t SDB_GetUsedSize(void)
{
     return sizeof(school_system);

}

void SDB_AddEntry(uint8_t id, uint16_t year, uint8_t CourseID, uint8_t Grade)
{
   // to prevent over writing on previous data
   int i=0;
    for(i=0;i<MAX_STUDENT_NUMBER;i++)
    {
        student[i].Student_ID[i]=id;
        student[i].Year_of_Grade=year;
        student[i].Course_ID[i]=CourseID;
        student[i].Course_Grade[i]=Grade;
    if(student[i].Student_ID[i] )
    {
        printf("Data is added successfully\n");
        break;
    }
    }
      //printf("%d \n",id_list[i].Student_ID[i] );
}

void SDB_DeleteEntry(uint8_t id)
{
    uint8_t i=0;

    for(i=0;i<MAX_STUDENT_NUMBER;i++){
        if(student[i].Student_ID==id)
        {
            student[i].Student_ID[i]=0;
            student[i].Course_Grade[i]=0;
            student[i].Course_ID[i]=0;
            student[i].Year_of_Grade=0;
        }
    }
    printf("Data is Removed \n");
}

void SDB_ReadEntry(uint8_t id, uint8_t CourseID, uint8_t* Grade )
{
   uint8_t i=0;
   for(i=0; i<MAX_STUDENT_NUMBER;i++)
    {
      if(student[i].Student_ID[i]==id)
      {
          if(CourseID<MAX_COURSES){
            *Grade =student[i].Course_Grade[CourseID];
            return;
          }
     else
        *Grade=0;

      }

   }
}

void SDB_GetIdList(uint8_t* Count,uint8_t* List)
{
   uint8_t arr[20]={0};
   uint8_t i =0;
   uint8_t counter=0;
   for (i=0;i<MAX_STUDENT_NUMBER;i++)
  {

    if(id_list[i].Student_ID[i] !=0)
    {
        * List =id_list[i].Student_ID[i];
        counter++;
    }
   *Count=counter;
   }

}

void SDB_IsIdExist(uint8_t ID)
{
uint8_t i=0;
 for(i=0;i<MAX_STUDENT_NUMBER;i++)
{
   if(id_list[i].Student_ID[i] =ID)
   {
    printf("id is exist ");

    break;
   }
   else
  {
    printf("id is not exist ");
    break;
   }

 }

}

