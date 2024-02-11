#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int PRE=6;

double sqrt_num(int n,int precision){
	double ans=0;
	int si=0,ei=n;
	while(si<=ei){
		int mid=si+(ei-si)/2;
		if(mid*mid==n){
			ans=mid;
			break;
		}
		else if(mid*mid<n){
			si=mid+1;
		}
		else ei=mid-1;
	}

	double inc=0.1;
	for(int i=0;i<PRE;i++){
		while(ans*ans<=n){
			ans+=inc;
		}
		ans-=inc;
		inc/=10;
	}

	return ans;
}

int main(){
	int n; scanf("%d",&n);
	double ans=sqrt_num(n,PRE);
	printf("%lf\n",ans);
}