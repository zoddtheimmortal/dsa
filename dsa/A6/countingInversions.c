#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int merge(int* arr,int si,int mid,int ei){
	int i=si,j=mid+1,k=0,ans=0;
	int temp[ei-si+1];

	while(i<=mid&&j<=ei){
		if(arr[i]<=arr[j]) temp[k++]=arr[i++];
		else{
			ans+=(mid-i+1);
			temp[k++]=arr[j++];
		}
	}

	while(i<=mid) temp[k++]=arr[i++];
	while(j<=ei) temp[k++]=arr[j++];

	i=si,k=0;
	while(i<=ei) arr[i++]=temp[k++];

	return ans;
}

int sort(int* arr,int si,int ei){
	if(si>=ei) return 0;
	int mid=si+(ei-si)/2;
	int x=sort(arr,si,mid);
	int y=sort(arr,mid+1,ei);
	int z=merge(arr,si,mid,ei);
	return x+y+z;
}

int main(){
	int n; scanf("%d",&n);
	int* arr=(int*) malloc(sizeof(int)*n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	int inv=sort(arr,0,n-1);
	printf("%d\n",inv);

	free(arr);
}