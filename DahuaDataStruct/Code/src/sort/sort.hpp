#ifndef __SORT_H__
#define __SORT_H__

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

template <typename T = int>

class Sort
{
private:
    T *m_element;
	T *m_element_bak;
    int m_size;
    void swap(T &a, T &b);

public:
    Sort() {}
    Sort(const int size, T *element);
    ~Sort() {}

    T getElem(int index) { return m_element[index]; }
	void resetElem();
    void printElem(bool bsorted);
	void printElem(int n);
    
	bool bubbleSort();
	bool selectSort();
    bool insertSort();
    bool quickSort();
	bool heapSort();
	bool shellSort();
	bool mergeSort();
	bool countingSort();
	bool bucketSort();
	bool radixSort();
    template <typename U>
    friend bool operator>(const Sort<U> &a, const Sort<U> &b);
    template <typename U>
    friend bool operator<(const Sort<U> &a, const Sort<U> &b);
    template <typename U>
    friend bool operator==(const Sort<U> &a, const Sort<U> &b);
};

#endif // __SORT_H__
