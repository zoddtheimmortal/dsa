#include<stdio.h>
int main(){
	int t; scanf("%d",&t);
	while(t--){
		int a,b; scanf("%d %d",&a,&b);
		int sub=b-a;
	// 	if(sub>0){
	// 		if(sub%2!=0) printf("1\n");
	// 		else printf("2\n");
	// 	}
	// 	else if(sub<0){
	// 		if(sub%2==0) printf("1\n");
	// 		else printf("2\n");
	// 	}
	// 	else printf("0\n");
	// }
		(sub>0)?(sub%2!=0?printf("1\n"):printf("2\n")):(sub==0?printf("0\n"):(sub%2==0?printf("1\n"):printf("2\n")));
}}