#include <stdio.h>

int main() {
    int n = 6;

    for (int i = 0; i < (1 << n); i++) {
        int grayCode = i ^ (i >> 1);

        for (int j = n - 1; j >= 0; j--) {
            printf("%d", (grayCode >> j) & 1);
        }
        printf("\n");
    }

    return 0;
}
