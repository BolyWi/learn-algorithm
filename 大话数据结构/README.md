# 大话数据结构学习笔记
## P01 绪论
### 概念、术语
- 数据
- 数据元素
- 数据项
- 数据对象
- 数据结构
### 逻辑结构和物理结构
- 逻辑结构
  - 集合结构
  - 线性结构
  - 树形结构
  - 图形结构
- 物理结构
  - 顺序存储结构
  - 链式存储结构


## P02 算法

## P03 线性表

```c
/*合并La，Lb中的元素到La，去除相同元素*/
void union(List *La, List *Lb)
{
    int La_len, Lb_len, i;
    ElemType e;
    La_len = ListLength(La);
    Lb_len = ListLength(Lb);
    for (i = 1; i < Lb_len; i++)
    {
        GetElem(Lb, i, e);
        if (!LocateElem(La, e, equal))
            ListInsert(La, ++La_len, e);
    }
}
```

### 线性表的顺序存储结构

- 线性表定义

```c
#define MAXSIZE 20
typedef int ElemType;
typedef struct
{
    ElemType data[MAXSIZE]; // 数组的长度
    int length;			   // 线性表的长度
}SqList;
```

- 地址计算

### 插入删除操作

- 获取元素

  ```c
  #define OK 1
  #define ERROR 0
  #define TRUE 1
  #define FALSE 0
  typedef int Status;
  Status GetElem(SqList L, int i, ElemType *e)
  {
      if (L.length == 0 || i < 1 || i > L.length)
          return ERROR;
      *e = L.data[i-1];
      return OK;
  }
  ```

  

- 插入操作

  ```c
  Status ListInsert(SqList *L, int i, ElemType e)
  {
      int k;
      if (L->length == MAXSIZE)
          return ERROR;
      if (i < 1 || i > L->length + 1)
          return ERROR;
      if (i <= L->length)
      {
          for (k = L->length - 1; k >= i-1; k--)
              L->data[k+1] = L->data[k];
      }
      L->data[i-1] = e;
      L->length++;
      
  }
  ```

  

- 删除操作