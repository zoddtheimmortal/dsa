#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <limits.h>
	
#define max(a,b) ((a>b)?(a):(b))
#define min(a,b) ((a<b)?(a):(b))

int n,k;

int recur_div(int* arr,int* parts,int idx){
	if(idx==n){
		int max_beaut=0;
		for(int i=0;i<k;i++){
			// printf("%d ",parts[i]);
			max_beaut=max(max_beaut,parts[i]);
		}
		// printf("\n");
		return max_beaut;
	}

	int min_beaut=INT_MAX;
	for(int i=0;i<k;i++){
		parts[i]+=arr[idx];
		int temp=recur_div(arr,parts,idx+1);
		parts[i]-=arr[idx];

		min_beaut=min(min_beaut,temp);
	}

	return min_beaut;
}

int main(){
	freopen("beaut.in","r",stdin);
	freopen("beaut.out","w",stdout);
	scanf("%d %d",&n,&k);
	int* arr=(int*) malloc(sizeof(int)*n);
	int* parts=(int*) malloc(sizeof(int)*k);

	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	for(int i=0;i<k;i++) parts[i]=0;

	int ans=recur_div(arr,parts,0);
	printf("%d\n",ans);

	free(parts); free(arr);
}