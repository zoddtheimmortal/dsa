#include<stdio.h>
int main(){
	int t; scanf("%d",&t);
	while(t--){
		int n; scanf("%d",&n);
		int k=n; int size=0,ten=1,a[7]={0};
		// while(k){
		// 	if(k%10) size++;
		// 	k=k/10;
		// }
		// printf("%d\n",size);
		// k=n;
		// while(k){
		// 	if(k%10){
		// 		printf("%d ",(k%10)*ten);
		// 	}
		// 	k=k/10; ten*=10;
		// }
		// printf("\n");
		while(k){
			if(k%10){
				a[size]=(k%10)*ten;
				size++;
			}
			k/=10; ten*=10;
		}
		printf("%d\n",size);
		for(int i=0;i<size;i++){
			printf("%d ",a[i]);
		}
		printf("\n");
	}	
}