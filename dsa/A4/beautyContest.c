#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <limits.h>

#define max(a,b) ((a>b)?(a):(b))
#define min(a,b) ((a<b)?(a):(b))

int n,k;

int recurse_packs(int* arr,int idx,int* parts){
	if(idx==n){
		int max_beaut=0;
		for(int i=0;i<k;i++){
			max_beaut=max(max_beaut,parts[i]);
		}
		return max_beaut;
	}

	int min_beaut=INT_MAX;
	for(int i=0;i<k;i++){
		parts[i]+=arr[idx];
		int temp=recurse_packs(arr,idx+1,parts);
		parts[i]-=arr[idx];
		min_beaut=min(min_beaut,temp);
	}

	return min_beaut;
}

int main(){
	scanf("%d %d",&n,&k);
	int* arr=(int*) malloc(sizeof(int)*n);
	int* parts=(int*) malloc(sizeof(int)*k);

	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	for(int i=0;i<k;i++) parts[i]=0;

	int ans=recurse_packs(arr,0,parts);
	printf("%d\n",ans);

	free(arr); free(parts);
}