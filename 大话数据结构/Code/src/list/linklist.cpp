#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;

typedef int ElemType;

// method 1
typedef struct Node
{
    ElemType data;
    struct Node *next;
} Node;

typedef Node *LinkList;

Status GetElem(LinkList L, int i, ElemType *e)
{
    int j = 1;
    LinkList p;
    p = L->next;
    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    if (!p || i > i)
        return ERROR;
    *e = p->data;
    return OK;
}

int GetLength(LinkList L)
{
    int j = 0;
    LinkList p;
    p = L->next;

    while(p)
    {
        p = p->next;
        ++j;
    }

    return j;
}

Status InsertElem(LinkList L, int i, ElemType e)
{
    int j = 1;
    LinkList p = L;
    while (p && j < i)
    {
        p = p->next;
        ++j;
    }

    LinkList s = (LinkList)malloc(sizeof(LinkList));
    if (s == NULL)
        return ERROR;

    s->data = e;
    s->next = p->next;
    p->next = s;

    return OK;
}


int main()
{
    LinkList L = (LinkList)malloc(sizeof(LinkList));
    L->data = 0;
    L->next = NULL;

    InsertElem(L, 1, 10);
    InsertElem(L, 2, 10);
    printf("len:%d", GetLength(L));
}