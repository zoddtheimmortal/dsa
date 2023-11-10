#include<iostream>
using namespace std;
int length(char s[]);
int main(){
	char s[100];
	cin>>s;
	int l=length(s);	
	cout<<l<<endl;
}

int length(char s[]){
	if(s[0]=='\0'){
		return 0;
	}
	int smallStringLength=length(s+1);
	return 1+smallStringLength;
}