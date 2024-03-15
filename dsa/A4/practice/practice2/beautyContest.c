#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <limits.h>

#define max(a,b) ((a>b)?(a):(b))
#define min(a,b) ((a<b)?(a):(b))

int n,k;

int recur_beaut(int* arr,int* packs,int idx){
	if(idx==n){
		int max_beaut=0;
		for(int i=0;i<k;i++){
			max_beaut=max(max_beaut,packs[i]);
		}
		return max_beaut;
	}

	int min_beaut=INT_MAX;
	for(int i=0;i<k;i++){
		packs[i]+=arr[idx];
		int temp=recur_beaut(arr,packs,idx+1);
		packs[i]-=arr[idx];
		min_beaut=min(min_beaut,temp);
	}
	return min_beaut;
}

int main(){
	scanf("%d %d",&n,&k);
	int* arr=(int*) malloc(sizeof(int)*n);
	int* packs=(int*) malloc(sizeof(int)*k);

	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	for(int i=0;i<k;i++) packs[i]=0;

	int ans=recur_beaut(arr,packs,0);
	printf("%d\n",ans);

	free(arr);
}