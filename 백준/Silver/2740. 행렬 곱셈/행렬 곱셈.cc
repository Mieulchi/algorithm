#include <stdio.h>

int mat1[100][100];
int mat2[100][100];
int ans[100][100];

int n1, n2, m1, m2;

void solve() {
    for(int i=0;i<n1;i++) {
        for(int j=0;j<m2;j++) {
            for(int k=0;k<m1;k++){
                ans[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main(){
    scanf("%d %d", &n1, &m1);
    for(int i=0;i<n1;i++){
        for(int j=0;j<m1;j++){
            scanf("%d", &mat1[i][j]);
        }
    }
    scanf("%d %d", &n2, &m2);
    for(int i=0;i<n2;i++){
        for(int j=0;j<m2;j++){
            scanf("%d", &mat2[i][j]);
        }
    }
    solve();
    for(int i=0;i<n1;i++){
        for(int j=0;j<m2;j++){
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
}