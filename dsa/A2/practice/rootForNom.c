#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int PRE=6;

double sqr_root(int n,int precision){
	double ans=0;
	int si=1,ei=n;
	while(si<=ei){
		int mid=si+(ei-si)/2;
		if(mid*mid<=n){
			ans=mid;
			si=mid+1;
		}else ei=mid-1;
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
	double ans=sqr_root(n,PRE);
	printf("%lf\n",ans);
}