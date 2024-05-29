#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e5)
#define MOD ((unsigned int)1e9+7)

int n;
int arr[MAX_N],idx[MAX_N],output[MAX_N];

void countSort(int n){
	int count[n+1];
	for(int i=0;i<=n;i++) count[i]=0;
	for(int i=0;i<n;i++) count[arr[i]]++;
	for(int i=1;i<=n;i++) count[i]+=count[i-1];

	for(int i=n-1;i>=0;i--){
		output[count[arr[i]]-1]=arr[i];
		idx[count[arr[i]]-1]=i+1;
		count[arr[i]]--;
	}
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	countSort(n);
	for(int i=0;i<n;i++) printf("%d ",output[i]);
	printf("\n");
	for(int i=0;i<n;i++) printf("%d ",idx[i]);
	printf("\n");
}