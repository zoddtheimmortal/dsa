#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void sort(float* arr,int n){
	for(int i=1;i<n;i++){
		float key=arr[i];
		int j=i-1;
		while(j>=0&&arr[j]>key){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}

int main(){
	int n; scanf("%d",&n);
	float* arr=(float*) malloc(sizeof(float)*n);
	for(int i=0;i<n;i++) scanf("%f",&arr[i]);

	float** buckets=(float**) malloc(sizeof(float*)*n);
	for(int i=0;i<n;i++) buckets[i]=(float*) malloc(sizeof(float)*n);
	int size[n]; for(int i=0;i<n;i++) size[i]=0;

	for(int i=0;i<n;i++){
		int bi=n*arr[i];
		buckets[bi][size[bi]++]=arr[i];
	}

	for(int i=0;i<n;i++){
		sort(buckets[i],size[i]);
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<size[i];j++) printf("%.2f ",buckets[i][j]);
	}
	printf("\n");
	for(int i=0;i<n;i++) printf("%d ",size[i]);
	printf("\n");
}