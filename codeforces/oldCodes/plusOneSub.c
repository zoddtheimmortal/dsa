#include<stdio.h>
#define Max(a,b) (a>b)?a:b
int main(){
	int t; scanf("%d",&t);
	while(t--){
		int n; scanf("%d",&n);
		int arr[n],max=0;
		for(int i=0;i<n;i++){
			scanf("%d",&arr[i]);
			max=Max(max,arr[i]);
		}
		int min=0;
		for(int j=0;j<n;j++){
			min=Max(max-arr[j],min);
		}
		printf("%d\n",min);
	}	
}