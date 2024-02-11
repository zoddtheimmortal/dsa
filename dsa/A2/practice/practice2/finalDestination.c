#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int n,k; scanf("%d %d",&n,&k);
	int arr[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) scanf("%d",&arr[i][j]);
	}

	int r_si=0,r_ei=n-1,c_si=0,c_ei=n-1,flag=0,found=0;
	while(r_si<=r_ei && c_si<=c_ei){
		int r_mid=r_si+(r_ei-r_si)/2;
		int c_mid=c_si+(c_ei-c_si)/2;

		if(flag==0){
			if(k>=arr[r_mid][0] && k<=arr[r_mid][n-1]){
				flag=1;
				continue;
			}
			else if(k<arr[r_mid][0]) r_ei=r_mid-1;
			else if(k>arr[r_mid][n-1]) r_si=r_mid+1;
		}
		if(flag==1){
			if(k==arr[r_mid][c_mid]){ found=1; break; }
			else if(k>arr[r_mid][c_mid]) c_si=c_mid+1;
			else c_ei=c_mid-1;
		}
	}

	printf("%s\n",(found?"YES":"NO"));
}