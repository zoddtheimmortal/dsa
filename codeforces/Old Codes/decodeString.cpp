#include<iostream>
using namespace std;
void decodeCode(string str,char op[]);
int main(){
	string code; cin>>code;
	char op[1000];
	decodeCode(code,op);
	cout<<op<<endl;	
}

void decodeCode(string str,char op[]){
	if(str[0]=='\0'){
		op[0]='\0';
		return;
	}
	else if(str[2]!='0'){
		op[0]=(char)('a'+stoi(str)-1);
		decodeCode(str.substr(1),op+1);
	}
	else{
		int x=stoi(str.substr(0,2));
		cout<<x<<" "<<(char)('a'+(x-1))<<endl;
		op[0]=(char)('a'+(x-1));
		decodeCode(str.substr(2),op+1);
	}
}