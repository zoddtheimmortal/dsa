#include<iostream>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		char str[101]; cin>>str;
		int countA=0,countB=0,countC=0;
		for(int i=0;str[i]!='\0';i++){
			(str[i]=='A')?(countA++):((str[i]=='B')?(countB++):(countC++));
		}
		if(countA+countC==countB) printf("YES\n");
		else printf("NO\n");
	}	
}