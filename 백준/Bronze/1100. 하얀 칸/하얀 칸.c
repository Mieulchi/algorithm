#include <stdio.h>

int ans;

int main() {
    for(int i=0;i<8;++i){
        char c[8] = {};
        scanf("%s", c);
        for(int j=0;j<8;++j){
            if (!((i + j) % 2) && c[j] == 'F') {
                ++ans;
            }
        }
    }
    printf("%d",ans);
}