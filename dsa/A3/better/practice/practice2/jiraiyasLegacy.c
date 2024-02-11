#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int n; scanf("%d\n",&n);
	char* arr=(char*) malloc(sizeof(char)*n);
	scanf("%[^\n]s",arr);

	int si=0,ei=n-1;
	while(si<ei){
		while(si<ei && arr[si]!='a'&&arr[si]!='e'&&arr[si]!='o'&&arr[si]!='u'&&arr[si]!='i'){
			si++;
		}
		while(si<ei && arr[ei]!='a'&&arr[ei]!='e'&&arr[ei]!='o'&&arr[ei]!='u'&&arr[ei]!='i'){
			ei--;
		}

		char t=arr[si];
		arr[si]=arr[ei];
		arr[ei]=t;
		si++; ei--;
	}

	printf("%s\n",arr);

	free(arr);
}