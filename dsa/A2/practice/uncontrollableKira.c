#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <limits.h>

#define max(a,b) ((a>b)?(a):(b))

int main(){
	int n; scanf("%d",&n);
	int* arr=(int*) malloc(sizeof(int)*n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	int min_stock=INT_MAX,ans=0,temp=0;
	for(int i=0;i<n;i++){
		if(arr[i]<=min_stock){
			ans+=temp;
			min_stock=arr[i];
			temp=0;
		}
		temp=max(temp,arr[i]-min_stock);
	}
	printf("%d\n",ans);
}