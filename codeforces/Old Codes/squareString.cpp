#include<iostream>
using namespace std;
void squareCheck(char str[],int n);
int main(){
	int t; cin>>t;
	while(t--){
		char str[101]; cin>>str;
		int i=0; for(;str[i]!='\0';i++);
		if(i%2==0){
			squareCheck(str,i);
		}
		else{
			printf("NO\n");
		}
	}	
}

void squareCheck(char str[],int n){
	for(int i=0;i<n/2;i++){
		if(str[i]!=str[(n/2)+i]){
			printf("NO\n"); return;
		}
	}
	printf("YES\n"); return;
}
