#include<stdio.h>
int main(){
	int t; scanf("%d",&t);
	while(t--){
		int arr[4]; scanf("%d %d %d %d",&arr[0],&arr[1],&arr[2],&arr[3]);
		int count=0;
		for(int i=1;i<4;i++){
			if(arr[i]>arr[0]){
				count++;
			}
		}
		printf("%d\n",count);

	}	
}