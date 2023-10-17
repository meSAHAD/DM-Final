#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This function generates all n bit Gray codes and prints the generated codes
void generateGrayCode(int n)
{
    // Base case
    if (n <= 0)
        return;

    // 'arr' will store all generated codes
    char **arr = (char **)malloc(sizeof(char *) * (1 << n));
    for (int i = 0; i < (1 << n); i++)
    {
        arr[i] = (char *)malloc(sizeof(char) * (n + 1));
    }

    // Start with one-bit pattern
    strcpy(arr[0], "0");
    strcpy(arr[1], "1");

    // Every iteration of this loop generates 2*i codes from previously
    // generated i codes.
    int i, j;
    for (i = 2; i < (1 << n); i = i << 1)
    {
        // Enter the previously generated codes again in arr[] in reverse
        // order. Now arr[] has double the number of codes.
        for (j = i - 1; j >= 0; j--)
        {
            strcpy(arr[i + j], arr[j]);
        }

        // Append '0' to the first half
        for (j = 0; j < i; j++)
        {
            strcat(arr[j], "0");
        }

        // Append '1' to the second half
        for (j = i; j < 2 * i; j++)
        {
            strcat(arr[j], "1");
        }
    }

    // Print contents of arr[]
    for (i = 0; i < (1 << n); i++)
    {
        printf("%s\n", arr[i]);
        free(arr[i]);
    }

    // Free the memory allocated for arr
    free(arr);
}

// Driver program to test the generateGrayCode function
int main()
{
    int n=6;
    generateGrayCode(n);
    return 0;
}
