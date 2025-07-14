#include <stdio.h>
int ans,idx;
int main(){int n;for(int i=0;i<9;i++){scanf("%d", &n);if(n>ans){ans=n;idx=i+1;}}printf("%d\n%d",ans,idx);}