#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)
#define PRE 6

const unsigned int MUL=1e6;

int si,ei;
int a,b,c,d;
double peak=INT_MIN;

double func(double x){
	return (a*x*x*x)+(b*x*x)+(c*x)+d;
}

int check(int x){
	return func(x)>peak;
}

int main(){
	scanf("%d %d",&si,&ei);
	scanf("%d %d %d %d",&a,&b,&c,&d);

	int unit=0;
	while(si<=ei){
		int mid=si+(ei-si)/2;
		if(check(mid)){
			unit=mid;
			peak=func(mid);
			ei=mid-1;
		}
		else si=mid+1;
	}
	printf("%lf\n",unit);
}