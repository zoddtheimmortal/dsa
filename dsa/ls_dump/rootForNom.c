#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

#define PRE 6

double sqroot(int n){
	double ans=-1;
	int si=0,ei=n-1;
	while(si<=ei){
		int mid=si+(ei-si)/2;
		if(mid*mid<n){
			ans=mid;
			si=mid+1;
		}
		else ei=mid-1;
	}

	double inc=0.1;
	for(int i=0;i<PRE;i++){
		while(ans*ans<n){
			ans+=inc;
		}
		ans-=inc;
		inc/=10;	
	}

	return ans;
}

int main(){
	int n; scanf("%d",&n);

	double root=sqroot(n);
	printf("%lf\n",root);
}