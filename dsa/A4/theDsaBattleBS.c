#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	freopen("dsaBattle.out","w",stdout);
	int n,a,b; scanf("%d %d %d",&n,&a,&b);
	while(a>0 && b>0){
		int si=1,ei=a,k_rep=0;
		while(si<=ei){
			int mid=si+(ei-si)/2;
			if(mid>=a-(mid*b)){
				k_rep=mid;
				ei=mid-1;
			}else si=mid+1;
		}
		for(int i=0;i<k_rep;i++) printf("K");
		printf("O");
		a-=(k_rep);
		b--;
	}

	for(int i=0;i<a;i++) printf("K");
	printf("\n");
}