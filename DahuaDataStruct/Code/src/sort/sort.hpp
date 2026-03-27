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
	enum ENUM_SORT_TYPE{
		ENUM_NONE_SORT = 0,
		ENUM_BUBBLE_SORT,
		ENUM_SELECT_SORT,
		ENUM_INSERT_SORT,
		ENUM_QUICK_SORT,
		ENUM_HEAP_SORT,
		ENUM_SHELL_SORT,
		ENUM_MERGE_SORT,
		ENUM_COUNTING_SORT,
		ENUM_BUCKET_SORT,
		ENUM_RADIX_SORT
	};
	
private:
    T *m_element;
	T *m_element_bak;
    int m_size;
	int m_circleCnt;
    void swap(T &a, T &b);

public:
    Sort() {}
    Sort(const int size, T element[]);
	Sort(const int size, T element[], ENUM_SORT_TYPE type);
    ~Sort();

    T getElem(int index) { return m_element[index]; }
	
	void resetElem();
    void printElem(bool bsorted);
	void printElem(int n);

	bool bubbleSortSimple();    
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

// friend function
    template <typename U>
    friend bool operator > (const Sort<U> &a, const Sort<U> &b);
    template <typename U>
    friend bool operator < (const Sort<U> &a, const Sort<U> &b);
    template <typename U>
    friend bool operator == (const Sort<U> &a, const Sort<U> &b);
};

#endif // __SORT_H__
