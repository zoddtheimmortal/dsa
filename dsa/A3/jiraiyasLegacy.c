#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int n; scanf("%d\n",&n);
	char* arr=(char*) malloc(sizeof(char)*n);
	scanf("%[^\n]s",arr);

	int si=0,ei=n-1,f1=0,f2=0;
	while(si<=ei){
		if(arr[si]=='a' || arr[si]=='e' || arr[si]=='i' || arr[si]=='o' || arr[si]=='u'){
			f1=1;
		}else si++;

		if(arr[ei]=='a' || arr[ei]=='e' || arr[ei]=='i' || arr[ei]=='o' || arr[ei]=='u'){
			f2=1;
		}else ei--;

		if(f1==1 && f2==1){
			char t=arr[si];
			arr[si]=arr[ei];
			arr[ei]=t;
			si++; ei--;
			f1=0,f2=0;
		}
	}

	printf("%s\n",arr);
}