#include<iostream>
#include<string>
using namespace std;
int main(){
	int n; cin>>n;
	int flag=-1;n--;
	string rage="I hate";
	while(n--){
		rage+=" that ";
		if(flag==-1){
			rage+="I love";
			flag*=-1;
		}
		else{
			rage+="I hate";
			flag*=-1;
		}
	}
	cout<<rage+" it";
}