#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int n,m; scanf("%d %d",&n,&m);
	int a[n],b[m];
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int j=0;j<m;j++) scanf("%d",&b[j]);

	int temp[n+m];
	int i=0,j=0,k=0;
	while(i<n && j<m){
		if(a[i]<b[j]) temp[k++]=a[i++];
		else temp[k++]=b[j++];
	}
	while(i<n) temp[k++]=a[i++];
	while(j<m) temp[k++]=b[j++];

	for(int i=0;i<k;i++) printf("%d ",temp[i]);
	printf("\n");
}