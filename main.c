#include <stdio.h>
#include <stdlib.h>


void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition the array around a pivot
int partition(int arr[], int low, int high) 
{
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1; // Index of smaller element

    for (int j = low; j <= high - 1; j++) 
    {
        if (arr[j] <= pivot) 
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// QuickSort algorithm
void quickSort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Find the ith order statistic
int ithOrderStatistic(int arr[], int n, int i) 
{
    quickSort(arr, 0, n - 1);
    return arr[i - 1];
}

int main() 
{
    int arr[] = {12, 3, 5, 7, 19};
    int n = sizeof(arr) / sizeof(arr[0]);
    int i = 3; // Example: finding the 3rd order statistic

    int ith_statistic = ithOrderStatistic(arr, n, i);
    printf("\n The %dth order statistic is: %d\n", i, ith_statistic);

    return 0;
}
