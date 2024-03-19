#include<iostream>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		char str[101]; cin>>str;
		int x=anatoliCheck(str,1);
		if(x) cout<<"DA\n";
		else cout<<"NET\n";
	}
}	

int anatoliCheck(char str[],int win){
	if(str[0]=='\0') return win;
	else if(str[0]!=str[1])
}