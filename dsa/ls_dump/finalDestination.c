#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int main(){
	int n,k; scanf("%d %d",&n,&k);
	int arr[n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++) scanf("%d",&arr[i][j]);
	}

	int r_si=0,r_ei=n-1,c_si=0,c_ei=n-1;
	int r=-1,c=-1;
	while(r_si<=r_ei){
		int mid=r_si+(r_ei-r_si)/2;
		if(arr[mid][0]<=k&&k<=arr[mid][n-1]){
			r=mid;
			break;
		}
		else if(arr[mid][n-1]<k&&k<=arr[r_ei][n-1]) r_si=mid+1;
		else if(k<arr[mid][0]&&arr[r_si][0]<=k) r_ei=mid-1;
	}

	while(r!=-1&&c_si<=c_ei){
		int mid=c_si+(c_ei-c_si)/2;
		if(arr[r][mid]==k){
			c=mid;
			break;
		}
		else if(arr[r][mid]<k) c_si=mid+1;
		else c_ei=mid-1;
	}

	printf("%s\n",(r!=-1&&c!=-1?"YES":"NO"));
}