#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int n,k;

int* countingSort(int* arr,int exp){
	int count[16]={0};
	int* output=(int*) malloc(sizeof(int)*n);

	for(int i=0;i<n;i++) count[(arr[i]/exp)%16]++;
	for(int i=1;i<16;i++) count[i]+=count[i-1];

	for(int i=n-1;i>=0;i--){
		output[count[(arr[i]/exp)%16]-1]=arr[i];
		count[(arr[i]/exp)%16]--;
	}
	return output;
}

int* radixSort(int* arr){
	int exp=1;
	for(int i=0;i<=k;i++){
		arr=countingSort(arr,exp);
		exp*=16;
	}
	return arr;
}

int main(){
	scanf("%d %d",&n,&k);
	int* arr=(int*) malloc(sizeof(int)*n);
	for(int i=0;i<n;i++) scanf("%x",&arr[i]);

	arr=radixSort(arr);

	for(int i=0;i<n;i++) printf("%X ",arr[i]);
	printf("\n");
}