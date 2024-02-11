#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int MOD=1e9+7;

long long int arise(int x,int y){
	if(y==0) return 1LL;

	long long int half=arise(x,y/2);
	if(y%2==0){
		return (half*half)%MOD;
	}
	else return (((half*half)%MOD)*x)%MOD;
}

int main(){
	int n; scanf("%d",&n);
	int* a=(int*) malloc(sizeof(int)*n);
	int* b=(int*) malloc(sizeof(int)*n);

	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	for(int i=0;i<n;i++) scanf("%d",&b[i]);

	long long int ans=1;
	for(int i=0;i<n;i++){
		ans=(ans*arise(a[i],b[i]))%MOD;
	}

	printf("%d\n",ans);
}