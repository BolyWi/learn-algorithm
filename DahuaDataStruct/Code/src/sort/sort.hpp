#ifndef __SORT_H__
#define __SORT_H__

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

template <typename T = int>

class Sort
{
private:
    T *m_element;
    int m_size;
    void swap(T &a, T &b);

public:
    Sort() {}
    Sort(const int size, T *element);
    ~Sort() {}

    T getElem(int index) { return m_element[index]; }
    void printElem();

    bool bubbleSort();
    bool insertSort();
    bool quickSort();
    template <typename U>
    friend bool operator>(const Sort<U> &a, const Sort<U> &b);
    template <typename U>
    friend bool operator<(const Sort<U> &a, const Sort<U> &b);
    template <typename U>
    friend bool operator==(const Sort<U> &a, const Sort<U> &b);
};

#endif // __SORT_H__
