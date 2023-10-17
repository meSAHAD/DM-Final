#include <stdio.h>

int main() {
    int n, m;
    scanf("%d", &n);
    int set1[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &set1[i]);
    }

    scanf("%d", &m);
    int set2[m];
    for (int i = 0; i < m; i++) {
        scanf("%d", &set2[i]);
    }

    int unionresult[100], intersectionresult[100];
    int index1 = 0, index = 0;

    // Union
    for (int i = 0; i < n; i++) {
        unionresult[index1++] = set1[i];
    }

    for (int i = 0; i < m; i++) { //1(0) 3(1) 4(2)
        int notduplicate = 1;
        for (int j = 0; j < n; j++) { //3(0) 4(1) 5(2) 
            if (set2[i] == unionresult[j])
            {
                notduplicate = 0;
                break;
            }
        }
        if (notduplicate==1) {
            unionresult[index1++] = set2[i];
        }
    }

    // Intersection
    for (int i = 0; i < n; i++) { //1 2 3 4
        for (int j = 0; j < m; j++) { //3 4 5
            if (set1[i] == set2[j]) {
                intersectionresult[index++] = set1[i]; //inersectonresult[100] 0->3 1->4
                break;
            }
        }
    }

    printf("Union is: {");
    for (int i = 0; i < index1; i++) {
            printf("%d", unionresult[i]);
            if (i < index1 - 1) {
                printf(",");
            }
        
    }
    printf("}\n");

    printf("Intersection is: {");
    for (int i = 0; i < index; i++) {
       {
            printf("%d", intersectionresult[i]);
            if (i < index - 1) {
                printf(",");
            }
        }
    }
    printf("}\n");

    return 0;
}
