#include <stdio.h>

int linearSearch(int arr[], int n, int x);
int binarySearch(int arr[], int n, int x);
void scanArrayAndValue(int arr[], int *n, int *x);

int main()
{
    // freopen("input.txt", "r", stdin);
    int n, x, arr[100];

    scanArrayAndValue(arr, &n, &x);

    int linearComparisons = linearSearch(arr, n, x);
    int binaryComparisons = binarySearch(arr, n, x);

    printf("Linear Comparisons: %d\n", linearComparisons);
    printf("Binary Comparisons: %d\n", binaryComparisons);

    return 0;
}

void scanArrayAndValue(int arr[], int *n, int *x)
{
    scanf("%d", n);
    for (int i = 0; i < *n; i++)
        scanf("%d", &arr[i]);

    scanf("%d", x);
}

int linearSearch(int arr[], int n, int x)
{
    int comparisons = 0;
    for (int i = 0; i < n; i++)
    {
        comparisons++;
        if (arr[i] == x)
            return comparisons;
    }
    return comparisons;
}

int binarySearch(int arr[], int n, int x)
{
    int comparisons = 0;
    int left = 0, right = n - 1;
    while (left <= right)
    {
        comparisons++;
        int mid = left + (right - left) / 2;
        if (arr[mid] == x)
            return comparisons;
        else if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return comparisons;
}
