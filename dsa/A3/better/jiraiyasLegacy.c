#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int n; scanf("%d\n",&n);
	char* arr=(char*) malloc(sizeof(char)*n);
	scanf("%[^\n]s",arr);

	int si=0,ei=n-1,flag=0;
	while(si<=ei){
		if(arr[si]=='a' || arr[si]=='e' || arr[si]=='i' || arr[si]=='o' || arr[si]=='u'){
			if(flag==0) flag=1;
		}else si++;

		if(arr[ei]=='a' || arr[ei]=='e' || arr[ei]=='i' || arr[ei]=='o' || arr[ei]=='u'){
			if(flag==1) flag=2;
		}else ei--;

		if(flag==2){
			char tmp=arr[si];
			arr[si]=arr[ei];
			arr[ei]=tmp;
			si++; ei--;
			flag=0;
		}
	}
	printf("%s\n",arr);
	free(arr);
}