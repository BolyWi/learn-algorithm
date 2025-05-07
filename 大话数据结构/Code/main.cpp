#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

#define MAX_LENGTH 36

typedef int T;

typedef struct SqList{
    T data[MAX_LENGTH];
    int len;
}SqList;

int init_list(SqList *L)
{
    memset(L->data, 0, sizeof(T) *MAX_LENGTH);
    L->len = 0;
    return 0;
}

int insert_list(SqList *L, int index, T *e)
{
    if(L == NULL || L->len > MAX_LENGTH-1 || index > MAX_LENGTH-1)
        return -1;
    
    for (int i = L->len; i > index; i--)
    {
        L->data[i+1] = L->data[i];
    }

    L->data[index] = *e;
    L->len++;
    return 0;
}

int delete_list(SqList *L, int index, T *e)
{
    
}

int main()
{
    SqList L;
    init_list(&L);
    T a = 10;
    insert_list(&L, 10, &a);
    return 0;
}
