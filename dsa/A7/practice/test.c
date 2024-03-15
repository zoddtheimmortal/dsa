#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define N 26

int cmp(int a,int b){
	return a>b;
}

void heapify(int* arr,int n,int i){
	int left=2*i+1,right=2*i+2,p=i;
	if(left<n&&cmp(arr[p],arr[left])) p=left;
	if(right<n&&cmp(arr[p],arr[right])) p=right;

	if(p!=i){
		int temp=arr[p];
		arr[p]=arr[i];
		arr[i]=temp;
		heapify(arr,n,p);
	}
}

void buildHeap(int* arr,int n){
	for(int i=n/2-1;i>=0;i--) heapify(arr,n,i);
}

int main(){
	int n,k; scanf("%d %d",&n,&k);
	char* arr=(char*) malloc(sizeof(char)*n);
	for(int i=0;i<n;i++){
		char x; scanf("%c",&x);
		if(x==' '||x=='\n'){
			i--; continue;
		}
		arr[i]=x;
	}

	int count[N]={0};
	for(int i=0;i<n;i++) count[arr[i]-'a']++;

	int heap[N]={0},i=0;
	while(i<k){
		for(int j=0;j<N;j++){
			if(count[j]>0){
				count[j]--;
				heap[j]++;
				i++;
			}
			if(i==k) break;
		}
	}

	long long sum=0;
	for(int i=0;i<N;i++) sum+=(heap[i]*heap[i]);
	printf("%lld\n",sum);
	

	// buildHeap(heap,m);
	// i=0; long long sum=0;
	// while(i<k&&m>0){
	// 	int diff=(i+heap[0]<k?heap[0]:k-i);
	// 	i+=diff;
	// 	sum+=(diff*diff);
	// 	heap[0]=heap[--m];
	// 	heapify(heap,m,0);
	// }
	// printf("%lld\n",sum);
}