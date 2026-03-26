#include "sort.hpp"

#define SORT_DEBUG(fmt, ...) 								\
	do{														\
		printf("[sort_debug] file:%s line:%d, func:%s, "	\
		fmt,__FILE__, __LINE__,__func__, ##__VA_ARGS__);	\
	}while(0)												\

// fg color
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

// bg color
#define BG_RED     "\033[41m"
#define BG_GREEN   "\033[42m"
#define BG_YELLOW  "\033[43m"
#define BG_BLUE    "\033[44m"

// style
#define BOLD    "\033[1m"
#define UNDERLINE "\033[4m"
#define RESET   "\033[0m"

template <typename T>
void Sort<T>::swap(T &a, T &b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
Sort<T>::Sort(int size, T *element)
    : m_element(element), m_size(size)
{
	m_element_bak = new T[size];
	memcpy(m_element_bak, m_element, m_size* sizeof(m_element[0]));
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
	const char *color = bsorted ? GREEN"[" : RED"[";
	printf("%s", color);
    for(int i = 0; i < m_size; i++)
    {
        printf("%d ", m_element[i]);
    }
    printf("]" RESET "\n");
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
    for (int i = 0; i < m_size-1; i++) // 排序的轮数
    {
        for (int j = 0; j < m_size-1-i; j++) // 比较与交换
        {
            if(m_element[j] > m_element[j+1])
            {
                swap(m_element[j], m_element[j+1]);
            }
        }
		printElem(i);
    }
    return false;
}

template <typename T>
bool Sort<T>::selectSort()
{
    for(int i = 0; i < m_size - 1; i++)
    {
        int min = i;
        for(int j = i+1; j < m_size; j++)
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
	for(int i = 0, j = 0, key = 0; i < m_size; i++)
	{
		key = m_element[i];
		j = i-1;
		while((j>=0) && (m_element[j]>key))
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
bool Sort<T>::quickSort()
{
    return false;
}

template <typename U>
bool operator>(const Sort<U> &a, const Sort<U> &b)
{
    return false;
}

template <typename U>
bool operator<(const Sort<U> &a, const Sort<U> &b)
{
    return false;
}

template <typename U>
bool operator==(const Sort<U> &a, const Sort<U> &b)
{
    return false;
}

int main(int argc, char* argv[])
{
	char** cmd = argv;
	int arr[] = {49, 23, 17, 68, 14, 30, 24, 20, 18, 46};
	int len  = sizeof(arr) / sizeof(arr[0]);
	Sort<int> *sort = new Sort<int>(len, arr);
	sort->printElem(false);
	clock_t start, end;
	double cpu_time_used;
	
	start = clock();
	sort->bubbleSort();
	end = clock();

	sort->printElem(true);
	cpu_time_used = ((double)(end-start)) / CLOCKS_PER_SEC;
	SORT_DEBUG("#run time:%lf#\r\n", cpu_time_used);
	return 0;
}
