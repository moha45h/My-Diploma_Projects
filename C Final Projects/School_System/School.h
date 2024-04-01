#ifndef SCHOOL_H_INCLUDED
#define SCHOOL_H_INCLUDED
#include<stdint-gcc.h>

void SDB_IsFULL(void);
uint8_t SDB_GetUsedSize(void);
void SDB_AddEntry(uint8_t id, uint16_t year, uint8_t CourseID, uint8_t Grade);
void SDB_DeleteEntry(uint8_t id);
void SDB_ReadEntry(uint8_t id, uint8_t CourseID, uint8_t * Grade );
void SDB_GetIdList(uint8_t* Count,uint8_t * List);
void SDB_IsIdExist(uint8_t ID);

#endif // SCHOOL_H_INCLUDED
