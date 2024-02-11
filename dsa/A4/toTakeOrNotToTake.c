#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?(a):(b))

int main(){
	int n,t; scanf("%d %d",&n,&t);
	int* arr=(int*) malloc(sizeof(int)*n);
	int* dur=(int*) malloc(sizeof(int)*n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	for(int i=0;i<n;i++) scanf("%d",&dur[i]);

	int ans=0;
	for(int mask=0;mask<(1<<20);mask++){
		int temp=0,time=0;
		for(int i=0;i<n;i++){
			if(mask&(1<<i)){
				temp+=arr[i];
				time+=dur[i];
			}
		}
		if(time<=t) ans=max(ans,temp);
	}

	printf("%d\n",ans);

	free(dur);
	free(arr);
}