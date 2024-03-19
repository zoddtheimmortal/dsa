#include<iostream>
using namespace std;
int main(){
	int n,s=0; cin>>n;
	while(n--){
		char str[101];cin>>str;
		switch(str[0]){
		case 'T':
			s+=4;
			break;
		case 'C':
			s+=6;
			break;
		case 'O':
			s+=8;
			break;
		case 'D':
			s+=12;
			break;
		case 'I':
			s+=20;
			break;
		}
	}
	printf("%d",s);
}