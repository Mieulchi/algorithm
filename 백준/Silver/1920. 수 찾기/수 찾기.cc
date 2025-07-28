#include <algorithm>
using namespace std;

#include <stdio.h>
int arr[100000];
int main() {
    int n,m,t;scanf("%d",&n);for(int i=0;i<n;i++){scanf("%d",&arr[i]);}sort(arr, arr + n);scanf("%d",&m);while(m--){scanf("%d",&t);printf("%d\n",binary_search(arr,arr+n,t)?1:0);}
}