#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <limits.h>

#define max(a,b) ((a>b)?(a):(b))

int main(){
	int n; scanf("%d",&n);
	int* arr=(int*) malloc(sizeof(int)*n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	int min_buy=INT_MAX,max_profit=-1;
	for(int i=0;i<n;i++){
		if(arr[i]<min_buy) min_buy=arr[i];
		max_profit=max(max_profit,arr[i]-min_buy);
	}
	printf("%d\n",max_profit);
}