#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

void insertionSort(int arr[],int n){
	int i,key,j;
	for(int i=1;i<n;i++){
		key=arr[i];
		j=i-1;
		while(j>=0&&arr[j]>key){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}

int findMedian(int arr[],int n){
	insertionSort(arr,n);
	return arr[n/2];
}

int part(int arr[],int si,int ei,int x){
	int i;
	for(i=si;i<ei;i++){
		if(arr[i]==x) break;
	}

	int temp=arr[i];
	arr[i]=arr[ei];
	arr[ei]=temp;

	i=si;
	for(int j=si;j<ei;j++){
		if(arr[j]<=x){
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			i++;
		}
	}

	temp=arr[i];
	arr[i]=arr[ei];
	arr[ei]=temp;
	return i;
}

int select(int arr[],int si,int ei,int k){
	if(k>0&&k<=ei-si+1){
		int n=ei-si+1;
		int i=0,median[(n+4)/5];
		for(;i<n/5;i++){
			median[i]=findMedian(arr+si+(i*5),5);
		}
		if(i*5<n){
			median[i]=findMedian(arr+si+(i*5),n%5);
			i++;
		}

		int medOfMed=(i==1?median[i-1]:select(median,0,i-1,i/2));
		int p=part(arr,si,ei,medOfMed);

		if(p-si==k-1) return arr[p];
		if(p-si>k-1) return select(arr,si,p-1,k);
		return select(arr,p+1,ei,k-(p-si+1));
	}
	return MAX_N;
}

int main(){
	int n,k; scanf("%d %d",&n,&k);
	int arr[n]; for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	int ans=select(arr,0,n-1,n-k+1);
	printf("%d\n",ans);
}