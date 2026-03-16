#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

#define MAXSIZE 20

typedef int ElemType;

typedef struct
{
    ElemType data[MAXSIZE];
    int length;
} SqList;


Status GetElem(SqList L, int i, ElemType *e)
{
    if(L.length == 0|| i < 1 || i > L.length)
        return ERROR;
    *e = L.data[i-1];
    return OK;
}

Status InsertElem(SqList *L, int i, ElemType e)
{
    if(!L || L->length <= 0 || i > L->length)
        return ERROR;

    for(int j = L->length; j > i; j--)
    {
        L->data[j] = L->data[j-1];
    }
    L->data[i] = e;
    L->length++;
    return OK;
}

Status DeleteElem(SqList *L, int i, ElemType *e)
{
    if(!L || L->length <= 0 || i > L->length)
        return ERROR;

    *e = L->data[i];
    int j = 0;
    for(j = i; j< L->length-1; j++)
    {
        L->data[j] = L->data[j+1];
    }
    L->data[j] = 0;
    L->length--;

    return OK;
}

Status MoveElem(SqList *L, int i, int pos, bool Front)
{
    if(!L || L->length <= 0 || i > L->length)
        return ERROR;
    ElemType e;
    DeleteElem(L, i, &e);
    InsertElem(L, Front? i-pos:i+pos, e);
    return OK;
}