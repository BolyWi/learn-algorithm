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
    : m_element(element), m_size(size)
{
}

template <typename T>
void Sort<T>::printElem()
{

}

template <typename T>
bool Sort<T>::bubbleSort()
{
    for (int i = 0; i < m_size; i++)
    {
        for (int j = i; j < m_size - 1; j++)
        {
            if(m_element[i] > m_element[j])
            {
                swap(m_element[i], m_element[j]);
            }
        }
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
