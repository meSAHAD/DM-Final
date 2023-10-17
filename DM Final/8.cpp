#include <stdio.h>

// Global variable to count operations
int recursiveOperations = 0;
int iterativeOperations = 0;

int fibonacciRecursive(int n)
{
    recursiveOperations++;
    if (n <= 1)
        return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

int fibonacciIterative(int n)
{   // 0 1 2
     //0 1 1 2 3 5 8 13 21 34 55 89 144 233
    int fib[n + 1];
    fib[0] = 0;
    fib[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        iterativeOperations++;
        fib[i] = fib[i - 1] + fib[i - 2];
    }

    return fib[n];
}

int main()
{
    int n; 
    //1 2 3 4 5 6 7 8  9 
    //0 1 1 2 3 5 8 13 21 34 55 89 144 233
    scanf("%d", &n);

    if (n < 0)
        printf("Please enter a non-negative number.\n");
    else
    {
        recursiveOperations = 0;
        iterativeOperations = 0;

        int recursiveResult = fibonacciRecursive(n);
        printf("Fibonacci number at position %d (recursive): %d\n", n, recursiveResult);
        printf("Number of operations (recursive): %d\n", recursiveOperations);

        int iterativeResult = fibonacciIterative(n);
        printf("Fibonacci number at position %d (iterative): %d\n", n, iterativeResult);
        printf("Number of operations (iterative): %d\n", iterativeOperations);
    }

    return 0;
}
