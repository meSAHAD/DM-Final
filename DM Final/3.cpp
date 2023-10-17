#include <stdio.h>

int main()
{
    // freopen("input3.txt","r",stdin);

    int u;
    scanf("%d", &u);
    int universalset[u];
    for (int i = 0; i < u; i++)
        scanf("%d", &universalset[i]);

    int v;
    scanf("%d", &v);
    int comperativeset[v];
    for (int i = 0; i < v; i++)
        scanf("%d", &comperativeset[i]);

    int complementResult[10];
    int index = 0;

    for (int i = 0; i < u; i++)
    {
        int isInSet = 1;

        for (int j = 0; j < v; j++)
        {
            if (universalset[i] == comperativeset[j])
            {
                isInSet = 0;
                break;
            }
        }

        if (isInSet==1)
        {
            complementResult[index++] = universalset[i];
        }
    }

    printf("Complement of the set: {");
    for (int i = 0; i < index; i++)
    {
        printf("%d", complementResult[i]);

        if (i < index - 1)
        {
            printf(", ");
        }
    }
    printf("}\n");

    return 0;
}
