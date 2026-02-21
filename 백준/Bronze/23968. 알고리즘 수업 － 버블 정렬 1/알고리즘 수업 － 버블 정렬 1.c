#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[10000];
int a, b;

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    int cnt = 0;
    for (int i = n; i > 1; --i) {
        for (int j = 0; j < i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                cnt++;
                int tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;

                if (cnt == k) {
                    printf("%d %d", arr[j], arr[j + 1]);
                    return 0;
                }
            }
        }
    }

    printf("-1");




}