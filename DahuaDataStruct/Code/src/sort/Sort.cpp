#include "sort.hpp"

template <typename T>
void Sort<T>::swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
Sort<T>::Sort(int size, T *element)
    : m_element(element), m_size(size), m_circleCnt(0)
{
	m_element_bak = new T[size];
	memcpy(m_element_bak, m_element, m_size* sizeof(m_element[0]));
}

template <typename T>
Sort<T>::Sort(const int size, T element[], ENUM_SORT_TYPE type)
	: m_element(element), m_size(size)
{
	
}

template <typename T>
Sort<T>::~Sort()
{
	delete[] m_element_bak;
}

template <typename T>
void Sort<T>::resetElem()
{
	memset(m_element, 0, m_size * sizeof(m_element[0]));
	memcpy(m_element, m_element_bak, m_size* sizeof(m_element_bak[0]));
}

template <typename T>
void Sort<T>::printElem(bool bsorted)
{
	const char *color = bsorted ? GREEN"[ " : RED"[ ";
	printf("%s", color);
    for(int i = 0; i < m_size; i++)
    {
        printf("%d ", m_element[i]);
    }
    printf("]" RESET "\n");
	
	if(bsorted)
	{
		printf("Total circle cnt: %d \n", m_circleCnt);
	}
}

template <typename T>
void Sort<T>::printElem(int n)
{
	printf("No.%2d:", n);
    for(int i = 0; i < m_size; i++)
    {
        printf("%d ", m_element[i]);
    }
    putchar('\n');
}

template <typename T>
bool Sort<T>::bubbleSort()
{
    for (int i = 0; i < m_size-1; i++) 			// 排序的轮数
    {
        for (int j = 0; j < m_size-1-i; j++) 	// 比较与交换
        {
            if(m_element[j] > m_element[j+1])
            {
                swap(m_element[j], m_element[j+1]);
            }
			m_circleCnt++;
		}
		printElem(i);
    }
    return false;
}

template <typename T>
bool Sort<T>::bubbleSortSimple()
{
    for (int i = 0; i < m_size; i++) 				// 排序的轮数
    {
        for (int j = i+1; j <= m_size; j++) 		// 比较与交换
        {
            if(m_element[i] > m_element[j])
            {
                swap(m_element[i], m_element[j]);
            }
			m_circleCnt++;
		}
		printElem(i);
    }
    return false;
}

template <typename T>
bool Sort<T>::selectSort()
{
    for(int i = 0; i < m_size - 1; i++)	  //将最小值放到已排序序列末尾
    {
        int min = i;
        for(int j = i+1; j < m_size; j++) // 找到未排序中最小值
        {
			if(m_element[j] <m_element[min])
				min = j;
        }
        swap(m_element[min], m_element[i]);
		printElem(i);
    }
    return false;
}

template <typename T>
bool Sort<T>::insertSort()
{
	T key;
	for(int i = 0, j = 0; i < m_size; i++) // 依次取出未排序部分中的元素
	{
		key = m_element[i];
		j = i-1;
		while((j>=0) && (m_element[j]>key)) // 将取出的元素在已排序部分中找到合适的位置插入
		{
			m_element[j+1] = m_element[j];
			j--;
		}
		m_element[j+1] = key;
		printElem(i);
	}
    return false;
}

template <typename T>
bool Sort<T>::shellSort()
{
	for(int gap = m_size >> 1;gap > 0; gap >>=1)
	{
		for(int i = gap, j = 0; i < m_size; i++)
		{
			T temp = m_element[i];

			for(j = i - gap; j >= 0 && m_element[j] > temp; j -= gap)
			{
				m_element[j+gap] = m_element[j];
			}
			m_element[j+gap] = temp;
		}
		printElem(false);
	}
    return false;
}

template <typename T>
bool Sort<T>::mergeSort()
{
	T *a = m_element;
	T *b = (T*)malloc(m_size* sizeof(T));

	for(int seg = 1; seg < m_size; seg*=2)
	{
		for(int start = 0; start < m_size; start += seg*2)
		{
			int low = start;
			int mid = (start+seg) < m_size ? start+seg : m_size;
			int high = (start+seg*2) < m_size ? start+seg*2 :m_size;
			int k = low;
			int start1 = low, end1 = mid;
			int start2 = mid, end2 = high;
			while (start1 < end1 && start2 < end2)
				b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
			while (start1 < end1)
                b[k++] = a[start1++];
            while (start2 < end2)
                b[k++] = a[start2++];
		}

		T* temp = a;
		a = b;
		b = temp;
		printElem(false);
	}
	if(a != m_element)
	{
		for(int i = 0; i < m_size; i++)
			b[i] = a[i];
		b = a;
	}
	free(b);
    return false;
}

typedef struct _Range {
    int start, end;
} Range;

Range new_Range(int s, int e) {
    Range r;
    r.start = s;
    r.end = e;
    return r;
}

template <typename T>
bool Sort<T>::quickSort()
{
	Range r[m_size];
    int p = 0;
    r[p++] = new_Range(0, m_size - 1);
    while (p)
	{
        Range range = r[--p];
        if (range.start >= range.end)
            continue;
        int mid = m_element[(range.start + range.end) / 2];
        int left = range.start, right = range.end;
        do {
            while (m_element[left] < mid)
				++left;
            while (m_element[right] > mid)
				--right;
            if (left <= right)
			{
                swap(m_element[left], m_element[right]);
                left++;
                right--;
            }
        } while (left <= right);
        if (range.start < right)
			r[p++] = new_Range(range.start, right);
        if (range.end > left)
			r[p++] = new_Range(left, range.end);
    }
    return false;
}

template <typename U>
bool operator > (const Sort<U> &a, const Sort<U> &b)
{
    return false;
}

template <typename U>
bool operator < (const Sort<U> &a, const Sort<U> &b)
{
    return false;
}

template <typename U>
bool operator == (const Sort<U> &a, const Sort<U> &b)
{
    return false;
}

void test_sort(Sort<int> *sort)
{
	clock_t start, end;
	double cpu_time_used;

	sort->printElem(false);

	start = clock();
	sort->bubbleSort();
	end = clock();

	sort->printElem(true);
	cpu_time_used = ((double)(end-start)) / CLOCKS_PER_SEC;
	SORT_DEBUG("#run time:%lf#\r\n", cpu_time_used);
}

void test_labmda(void(*callback)())
{
	
	callback();
}

int main(int argc, char* argv[])
{
	char** cmd = argv;
	int arr[] = {49, 23, 17, 68, 14, 30, 24, 20, 18, 46};
	int len  = sizeof(arr) / sizeof(arr[0]);

	Sort<int> *sort = new Sort<int>(len, arr);
	test_sort(sort);
	test_labmda([](){printf("Hello lambda!\r\n");});
	return 0;
}
