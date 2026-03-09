#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int length;
} Array;

// Initialize the array
void InitArray(Array *arr) {
    arr->length = 0;
}

// Insert element at specific position
bool Insert(Array *arr, int index, int value) {
    if (arr->length >= MAX_SIZE || index < 0 || index > arr->length) {
        return false;
    }
    for (int i = arr->length; i > index; i--) {
        arr->data[i] = arr->data[i - 1];
    }
    arr->data[index] = value;
    arr->length++;
    return true;
}

// Delete element at specific position
bool Delete(Array *arr, int index, int *value) {
    if (arr->length == 0 || index < 0 || index >= arr->length) {
        return false;
    }
    *value = arr->data[index];
    for (int i = index; i < arr->length - 1; i++) {
        arr->data[i] = arr->data[i + 1];
    }
    arr->length--;
    return true;
}

// Get element at specific position
bool Get(const Array *arr, int index, int *value) {
    if (index < 0 || index >= arr->length) {
        return false;
    }
    *value = arr->data[index];
    return true;
}

// Print all elements
void Print(const Array *arr) {
    for (int i = 0; i < arr->length; i++) {
        printf("%d ", arr->data[i]);
    }
    printf("\n");
}

int main() {
    Array arr;
    InitArray(&arr);
    
    Insert(&arr, 0, 10);
    Insert(&arr, 1, 20);
    Insert(&arr, 1, 15);
    
    printf("Current Array: ");
    Print(&arr);
    
    int val;
    if (Get(&arr, 1, &val)) {
        printf("Element at index 1: %d\n", val);
    }
    
    if (Delete(&arr, 1, &val)) {
        printf("Deleted element: %d\n", val);
    }
    
    printf("After Deletion: ");
    Print(&arr);
    
    return 0;
}