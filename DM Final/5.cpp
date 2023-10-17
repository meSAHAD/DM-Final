#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

void printPowerSet(char *set, int set_size)
{
    unsigned int pow_set_size = pow(2, set_size);
    int counter, j;

    for (counter = 0; counter < pow_set_size; counter++)
    {
        printf("{");
         int isFirstElement = 1;
        for (j = 0; j < set_size; j++)
        {
            if (counter & (1 << j))
            { 
                if (!isFirstElement) {
                    printf(",");
                }
                printf("%c", set[j]);
                 isFirstElement = 0;
            }
        }
        printf("}");
        if (counter < pow_set_size-1)   printf(",");    
    }
}

void extractset(char *input1, char *set1, int *index)
{
    for (int i = 0; input1[i] != '\0'; i++) 
    {
        if (input1[i] == '{') 
        {
            int j = i + 1; // Start index of set1
            while (input1[j] != '}')
            {
                if (input1[j] >= '0' && input1[j] <= '9') // Check if the character is a digit
                { 
                    set1[*index] = input1[j]; // Store the number in the array
                    (*index)++;  //atoi converts the character into integer 
                    j++;
                } 
                else 
                {
                    j++; // Move to the next character
                }
            }
            break; // Exit the loop after finding the second bracket
        }
    }
}

/*Driver program to test printPowerSet*/
int main()
{
    char input1[100],set1[100];
    int index = 0; // Index for the set1 array
    scanf("%s", input1);
    
    extractset(input1, set1, &index); // Extract set1 from input1
    printPowerSet(set1, index); // Print power set of the extracted set1

    return 0;
}
