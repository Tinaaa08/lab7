#include <stdio.h>
#include <stdlib.h>

typedef struct element {
    int data;
    int numswaps;
} element;

void swap(element *xp, element *yp) {
    element temp = *xp;
    *xp = *yp;
    *yp = temp;
    xp->numswaps++;
    yp->numswaps++;
}

void bubbleSort(element arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (arr[j].data > arr[j+1].data)
                swap(&arr[j], &arr[j+1]);
}

void selectionSort(element arr[], int n) {
    int i, j, min_idx;
    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j].data < arr[min_idx].data)
                min_idx = j;

        if (min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
}

element* createArray(int data[], int n) {
    element *arr = (element*)malloc(n * sizeof(element));
    for(int i = 0; i < n; i++) {
        arr[i].data = data[i];
        arr[i].numswaps = 0;
    }
    return arr;
}

void printSwaps(element arr[], int n) {
    int totalSwaps = 0;
    for (int i = 0; i < n; i++) {
        printf("%d: %d \n", arr[i].data, arr[i].numswaps);
        totalSwaps += arr[i].numswaps;
    }
    printf("Total Number of Swaps: %d\n\n", totalSwaps / 2); 
}

int main() {
    int data1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int size1 = sizeof(data1)/sizeof(data1[0]);
    element *array1 = createArray(data1, size1);

    int data2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int size2 = sizeof(data2)/sizeof(data2[0]);
    element *array2 = createArray(data2, size2);

    bubbleSort(array1, size1);
    printf("Array1 Bubble Sort:\n");
    printSwaps(array1, size1);

    bubbleSort(array2, size2);
    printf("Array2 Bubble Sort:\n");
    printSwaps(array2, size2);

   
    free(array1);
    free(array2);
    array1 = createArray(data1, size1);
    array2 = createArray(data2, size2);

    selectionSort(array1, size1);
    printf("Array1 Selection Sort:\n");
    printSwaps(array1, size1);

    selectionSort(array2, size2);
    printf("Array2 Selection Sort:\n");
    printSwaps(array2, size2);

    
    free(array1);
    free(array2);

    return 0;
}
