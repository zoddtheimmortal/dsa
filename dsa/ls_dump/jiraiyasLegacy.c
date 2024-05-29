#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define MAX_N ((unsigned int)1e6)
#define MOD ((unsigned int)1e9+7)

int main(){
	int n; scanf("%d\n",&n);
	char arr[n]; scanf("%[^\n]s",arr);

	int si=0,ei=n-1;
	while(si<ei){
		while(si<n&&(arr[si]!='a'&&arr[si]!='e'&&arr[si]!='i'
			&&arr[si]!='o'&&arr[si]!='u')) si++;
		while(ei>=0&&(arr[ei]!='a'&&arr[ei]!='e'&&arr[ei]!='i'
			&&arr[ei]!='o'&&arr[ei]!='u')) ei--;

		if(si<ei){
			char temp=arr[si];
			arr[si]=arr[ei];
			arr[ei]=temp;
		}
		si++,ei--;
	}
	printf("%s\n",arr);
}