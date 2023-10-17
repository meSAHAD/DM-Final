#include <stdio.h>

void cartesianProduct(int set1[], int size1, int set2[], int size2)
{
    printf("Cartesian Product: {");
    for (int i = 0; i < size1; i++) //1(0) 3(1) 4(2)
    {
        for (int j = 0; j < size1; j++) //3(0) 4(1) 5(2) 
        {
            printf("(%d,%d)", set1[i], set2[j]);
            if (j < size1-1) printf(",");
        }
        if (i < size2-1) printf(",");

    }
    printf("}\n");
}

// Function to perform symmetric difference
void symmetricDifference(int set1[], int size1, int set2[], int size2) {
    printf("Symmetric Difference:\n");

    // Create a result set to store the symmetric difference
    int result[100];
    int index = 0;

    // Find elements in set1 that are not in set2
    for (int i = 0; i < size1; i++) {
        int isInSet2 = 0;
        for (int j = 0; j < size2; j++) {
            if (set1[i] == set2[j]) {
                isInSet2 = 1;
                break;
            }
        }
        if (!isInSet2) {
            result[index++] = set1[i];
        }
    }

    // Find elements in set2 that are not in set1
    for (int i = 0; i < size2; i++) {
        int isInSet1 = 0;
        for (int j = 0; j < size1; j++) {
            if (set2[i] == set1[j]) {
                isInSet1 = 1;
                break;
            }
        }
        if (!isInSet1) {
            result[index++] = set2[i];
        }
    }

    // Print the symmetric difference
    for (int i = 0; i < index; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
}

int main()
{
    //freopen("input4.txt","r",stdin);
    int size1;
    scanf("%d", &size1);
    int set1[size1];
    for (int i = 0; i < size1; i++) scanf("%d", &set1[i]);

    int size2;
    scanf("%d", &size2);
    int set2[size2];
    for (int i = 0; i < size2; i++) scanf("%d", &set2[i]);

    cartesianProduct(set1, size1, set2, size2);
    symmetricDifference(set1, size1, set2, size2);

    return 0;
}

