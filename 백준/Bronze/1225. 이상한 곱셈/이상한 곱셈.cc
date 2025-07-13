#include <stdio.h>
long long ans;
int main(){char c1[10001], c2[10001];scanf("%s %s", c1, c2);for(int i=0;c1[i]!='\0';i++){for(int j=0;c2[j]!='\0';j++){ans+=(c1[i]-'0')*(c2[j]-'0');}}printf("%lld",ans);}