#include<stdio.h>
int main(){
	int arr[4],max=0;
	for(int i=0;i<4;i++){
		scanf("%d",arr[i]);
		if(arr[i]>max) max=arr[i];
	}
	for(int i=0;i<4;i++){
		if(max==arr[i]) arr[i]=0;
	}
	int j=0;
	for(int i=0;i<4;i++){
		int sum=0;
		for(int j=0;j<4;j++){
			if(j==i) sum-=arr[j];
			else sum+=arr[j];
		}
		printf("%d ",sum);
	}
}