#include<stdio.h>
int main(){
	int n,k; scanf("%d %d",&n,&k);
	int arr[n],qual=0;
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for(int i=0;i<n;i++){
		if(arr[i]>0){
			if(arr[i]>=arr[k-1]){
				qual++;
			}
		}
	}
	printf("%d",qual);
}