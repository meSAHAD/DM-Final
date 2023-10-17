#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    long long int fib1 = 0, fib2 = 1, fib3;

    printf("Fibonacci numbers divisible by:\n");
    printf("5: ");
    for (int i = 1; i <= n; i++)
    {
        if (fib1 != 0 && fib1 % 5 == 0)
        {
            printf("%lld ", fib1);
        }                   //0 1 1 2 3 5 8 13 21 
        fib3 = fib1 + fib2; //1 2 3 4 5 6 7 8  9
        fib1 = fib2;   
        fib2 = fib3;
    }

    fib1 = 0;
    fib2 = 1;

    printf("\n7: ");
    for (int i = 1; i <= n; i++)
    {
        if (fib1 != 0 && fib1 % 7 == 0)
        {
            printf("%lld ", fib1);
        }
        fib3 = fib1 + fib2;
        fib1 = fib2;
        fib2 = fib3;
    }

    fib1 = 0;
    fib2 = 1;

    printf("\n11: ");
    for (int i = 1; i <= n+2; i++)
    {
        if (fib1 != 0 && fib1 % 11 == 0)
        {
            printf("%lld ", fib1);
        }
        fib3 = fib1 + fib2;
        fib1 = fib2;
        fib2 = fib3;
    }

    printf("\n");
    return 0;
}
