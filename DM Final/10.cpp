#include <stdio.h>

// Function to calculate the factorial of a number
unsigned long long factorial(int num)
{
    if (num == 0)
        return 1;
    unsigned long long result = 1;
    for (int i = 1; i <= num; i++) 
    {
        result = result * i;
    }
    return result;
}

int main()
{
    int n, r;
    scanf("%d%d", &n, &r);

    if (r < 0 || r > n)
    {
        printf("Invalid input: r should be a nonnegative integer not exceeding n.\n");
    }
    else
    {
        unsigned long long permutations = factorial(n) / factorial(n - r);
        unsigned long long combinations = factorial(n) / (factorial(r) * factorial(n - r));

        printf("Number of %d-permutations: %llu\n", r, permutations);
        printf("Number of %d-combinations: %llu\n", r, combinations);
    }

    return 0;
}
