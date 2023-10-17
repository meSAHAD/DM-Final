#include <stdio.h>

int main()
{
    int p, q;

    printf("Given the truth values of the propositions p and q,the truth values of the conjunction, disjunction, exclusive or,conditional statement, and biconditional are:\n");
    printf("p | q | p AND q | p OR q | p XOR q | p => q | p <=> q\n");
    printf("----------------------------------------------------\n");

    for (p = 0; p <= 1; p++)
    {
        for (q = 0; q <= 1; q++)
        {
            printf("%d | %d |    %d    |   %d    |    %d    |   %d    |    %d\n", p, q, p && q, p || q, (p && !q) || (!p && q), !p || q, (p && q) || (!p && !q));
        }
    }

    return 0;
}
