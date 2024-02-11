#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int n; scanf("%d\n",&n);
	char* arr=(char*) malloc(sizeof(char)*n);
	scanf("%[^\n]s",arr);
	
	int si=0,ei=0;
	while(si<n && ei<n){
		while(ei<n && arr[ei]!=' ') ei++;

		int jump=ei+1;
		ei--;
		while(si<ei){
			char temp=arr[si];
			arr[si]=arr[ei];
			arr[ei]=temp;
			si++; ei--;
		}

		si=jump,ei=jump;
	}

	printf("%s\n",arr);
}