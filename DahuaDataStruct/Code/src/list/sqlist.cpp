#include <stdio.h>

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

Status InsertElem(SqList L, int i, ElemType e)
{
    for(int j = L.length; j > i; j--)
    {
        L.data[j] = L.data[j-1];
    }
    L.data[i] = e;
    return OK;
}

Status DeleteElem(SqList L, int i, ElemType e)
{
    e = L.data[i];
    for(int j = i; j< L.length; j++)
    {
        L.data[j] = L.data[j+1];
    }
    return OK;
}
