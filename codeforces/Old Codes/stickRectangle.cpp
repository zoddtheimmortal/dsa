#include<iostream>
using namespace std;
int isRectangle(int a,int b,int c);
int main(){
	int t; cin>>t;
	while(t--){
		int a,b,c; cin>>a>>b>>c;
		if(isRectangle(a,b,c)) cout<<"Yes\n";
		else cout<<"No\n";
	}	
}

int isRectangle(int a,int b,int c){
	if(a==b && c%2==0) return 1;
	else if(b==c && a%2==0) return 1;
	else if(c==a && b%2==0) return 1;
	else if(a+b==c || b+c==a || c+a==b) return 1;
	return 0;
}