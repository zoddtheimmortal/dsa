#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int n,k; scanf("%d %d",&n,&k);
	int a[n],exists[n];
	for(int i=0;i<n;i++) exists[i]=0;
	for(int i=0;i<n;i++) scanf("%d",&a[i]);

	for(int i=0;i<n;i++) exists[a[i]-1]++;

	int m=0;
	for(int i=0;i<n;i++) m+=(exists[i]==0);

	int b[m];
	int i=0,j=0,ans=0;
	while(i<n){
		if(exists[i]==0) b[j++]=i+1;
		i++;
	}

	i=0,j=m-1,ans=0;
	while(i<j){
		if(b[i]+b[j]==k){
			ans=1; break;
		}
		else if(b[i]+b[j]<k) i++;
		else j--;
	}

	printf("%s\n",(ans==1?"YES":"NO"));
}