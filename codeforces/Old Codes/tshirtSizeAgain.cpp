#include<iostream>
using namespace std;
int pointSize(string str,int n);
int main(){
	int t; cin>>t;
	while(t--){
		string s1,s2;
		cin>>s1>>s2;
		int a=pointSize(s1,0),b=pointSize(s2,0);
		cout<<a<<" "<<b<<endl;
		if(a>b) cout<<">\n";
		else if(a<b) cout<<"<\n";
		else cout<<"=\n";
	}	
}

int pointSize(string str,int n){
	if(str[0]=='\0' || str[0]=='M') return n;
	else if(str[0]=='X' || str[0]=='L'){
		pointSize(str.substr(1),n+1);
	}
	else if(str[0]=='S'){
		pointSize(str.substr(1),(n+1)*(-1));
	}
}