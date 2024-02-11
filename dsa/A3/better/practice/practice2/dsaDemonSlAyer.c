#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int n; scanf("%d\n",&n);	
	char* arr=(char*) malloc(sizeof(char)*n);
	scanf("%[^\n]s",arr);

	int si=0,ei=0;
	while(si<=n && ei<=n){
		while(arr[ei]!=' '&&arr[ei]!='\0') ei++;
		int jump=ei+1;
		ei--;

		while(si<=ei){
			char t=arr[si];
			arr[si]=arr[ei];
			arr[ei]=t;
			si++; ei--;
		}

		si=ei=jump;
	}

	printf("%s\n",arr);

	free(arr);
}