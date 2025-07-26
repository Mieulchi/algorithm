#include <algorithm>
using namespace std;
#include <stdio.h>

int main() {
    int arr[50] = { 0 };
    int cpy[50];
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        cpy[i] = arr[i];
    }
    sort(cpy, cpy + n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (cpy[j] != -1 && cpy[j] == arr[i]) {
                printf("%d ", j);
                cpy[j] = -1;
                break;
            }
        }
    }
}