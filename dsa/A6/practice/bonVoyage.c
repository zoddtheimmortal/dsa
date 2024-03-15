#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define N 2e3
#define max(a,b) ((a>b)?(a):(b))

int main(){
	int n; scanf("%d",&n);
	int* arr=(int*) malloc(sizeof(int)*N);
	int size=0;
	for(int i=0;i<n;i++){
		int x,y; scanf("%d %d",&x,&y);
		arr[x-1]=1,arr[y]=-1;
		size=max(size,y);
	}
	arr=(int*) realloc(arr,sizeof(int)*size);

	for(int i=1;i<size;i++) arr[i]=arr[i-1]+arr[i];

	int* ans=(int*) malloc(sizeof(int)*size);
	int si=0,ei=0,k=0;
	while(si<size && ei<size){
		while(si<size&&arr[si]==0) si++;
		ei=si;
		while(ei<size&&arr[ei]!=0) ei++;
		ans[k++]=si+1; ans[k++]=ei;
		si=ei+1;
	}

	printf("%d\n",k/2);

	int i=0;
	while(i+1<k){
		printf("%d %d\n",ans[i],ans[i+1]);
		i+=2;
	}
}