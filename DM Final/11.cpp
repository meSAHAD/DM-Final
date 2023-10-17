#include <stdio.h>

void findLongestSubsequences(int arr[], int n)
{
    int lis[n]; // Longest Increasing Subsequence
    int lds[n]; // Longest Decreasing Subsequence

    // Initialize both arrays with 1 as the minimum length for any subsequence
    for (int i = 0; i < n; i++)
    {
        lis[i] = lds[i] = 1;
    }

    // Calculate the longest increasing subsequence
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
            {
                lis[i] = lis[j] + 1;
            }
        }
    }

    // Calculate the longest decreasing subsequence
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (arr[i] > arr[j] && lds[i] < lds[j] + 1)
            {
                lds[i] = lds[j] + 1;
            }
        }
    }

    // Find the maximum length of increasing and decreasing subsequences
    int maxLIS = lis[0];
    int maxLDS = lds[0];

    for (int i = 1; i < n; i++)
    {
        if (lis[i] > maxLIS)
        {
            maxLIS = lis[i];
        }
        if (lds[i] > maxLDS)
        {
            maxLDS = lds[i];
        }
    }

    printf("Longest Increasing Subsequence: %d\n", maxLIS);
    printf("Longest Decreasing Subsequence: %d\n", maxLDS);
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)  scanf("%d", &arr[i]);

    findLongestSubsequences(arr, n);

    return 0;
}
