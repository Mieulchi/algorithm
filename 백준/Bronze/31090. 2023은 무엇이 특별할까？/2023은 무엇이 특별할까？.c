#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    
    while(t--) {
        int n;
        scanf("%d", &n);
        printf((n + 1) % (n % 100) ? "Bye\n" : "Good\n");
    }
}