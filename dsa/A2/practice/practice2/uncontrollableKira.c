#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <limits.h>

#define max(a,b) ((a>b)?(a):(b))

int main(){
	int n; scanf("%d",&n);
	int* arr=(int*) malloc(sizeof(int)*n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	int min_stock=INT_MAX,max_profit=0,ans=0;
	for(int i=0;i<n;i++){
		if(min_stock>=arr[i]){
			min_stock=arr[i];
			ans+=max_profit;
			max_profit=0;
		}
		max_profit=max(max_profit,arr[i]-min_stock);
	}
	if(max_profit>0) ans+=max_profit;

	printf("%d\n",ans);
	free(arr);
}