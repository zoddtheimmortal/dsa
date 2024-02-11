#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

#define max(a,b) ((a>b)?(a):(b))

int main(){
	int n; scanf("%d",&n);
	int* arr=(int*) malloc(sizeof(int)*n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	int min_buy=INT_MAX,max_profit=0,ans=0,flag=0;

	for(int i=0;i<n;i++){
		if(min_buy>=arr[i]){
			min_buy=arr[i];
			ans+=max_profit;
			max_profit=0;
		}
		if(max_profit<arr[i]-min_buy && i==n-1) flag=1;
		max_profit=max(max_profit,arr[i]-min_buy);
	}
	if(flag) ans+=max_profit;

	printf("%d\n",ans);
}