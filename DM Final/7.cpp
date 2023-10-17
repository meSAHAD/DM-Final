#include <stdio.h>

int bubbleSort(int arr[], int n)
{
    int comparisons = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            comparisons++; // Count each comparison
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return comparisons;
}

int insertionSort(int arr[], int n)
{
    int comparisons = 0;
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            comparisons++; // Count each comparison
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    return comparisons;
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr1[n], arr2[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr1[i]);
    for (int i = 0; i < n; i++)
        arr2[i] = arr1[i];

    int bubbleComparisons = bubbleSort(arr1, n);
    printf("Bubble Sort Comparisons: %d\n", bubbleComparisons);

    int insertionComparisons = insertionSort(arr2, n);
    printf("Insertion Sort Comparisons: %d\n", insertionComparisons);

    return 0;
}
