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

	int si=0,ei=0;
	while(si<n&&ei<n){
		ei=si;
		while(ei<n&&arr[ei]!=' ') ei++;
		int p=si,q=ei-1;
		while(p<=q){
			char temp=arr[p];
			arr[p]=arr[q];
			arr[q]=temp;
			p++; q--;
		}
		si=ei+1;
	}

	printf("%s\n",arr);
}