#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int n,m; scanf("%d %d",&n,&m);
	int arr[n],brr[m];
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	for(int i=0;i<m;i++) scanf("%d",&brr[i]);

	int temp[n+m];
	int i=0,j=0,k=0;
	while(i<n && j<m){
		if(arr[i]<brr[j]) temp[k++]=arr[i++];
		else temp[k++]=brr[j++];
	}

	while(i<n) temp[k++]=arr[i++];
	while(j<m) temp[k++]=brr[j++];

	for(int i=0;i<k;i++){
		printf("%d ",temp[i]);
	}
	printf("\n");
}