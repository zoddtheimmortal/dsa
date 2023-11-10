#include<iostream>
using namespace std;
int pointSize(char str[],int n);
int main(){
	int t; cin>>t;
	while(t--){
		char s1[51],s2[51];
		cin>>s1>>s2;
		int a=pointSize(s1,0),b=pointSize(s2,0);
		if(a>b) cout<<">\n";
		else if(a<b) cout<<"<\n";
		else cout<<"=\n";
	}	
}

int pointSize(char str[],int n){
	if(str[0]=='\0' || str[0]=='M') return n;
	else if(str[0]=='X' || str[0]=='L'){
		pointSize(str+1,n+1);
	}
	else if(str[0]=='S'){
		pointSize(str+1,(n+1)*(-1));
	}
}