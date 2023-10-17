#include <stdio.h>

#define N 1000

int n, arr[N], dp[N];

int lis(int i) {
    if (dp[i] != -1) return dp[i];
    int ans = 1;
    for (int j = 0; j < i; j++) {
        if (arr[j] < arr[i]) {
            ans = (ans > (lis(j) + 1)) ? ans : (lis(j) + 1);
        }
    }
    return dp[i] = ans;
}

int lds(int i) {
    if (dp[i] != -1) return dp[i];
    int ans = 1;
    for (int j = 0; j < i; j++) {
        if (arr[j] > arr[i]) {
            ans = (ans > (lds(j) + 1)) ? ans : (lds(j) + 1);
        }
    }
    return dp[i] = ans;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        dp[i] = -1;
    }

    printf("Longest Increasing Subsequence: %d\n", lis(n - 1));

    for (int i = 0; i < n; i++) dp[i] = -1;
    printf("Longest Decreasing Subsequence: %d\n", lds(n - 1));

    return 0;
}
