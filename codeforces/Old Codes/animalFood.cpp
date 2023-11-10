#include<iostream>
using namespace std;
#define abs(a) a>0?a:-a
int main(){
	int t; cin>>t;
	while(t--){
		int a,b,c,x,y; cin>>a>>b>>c>>x>>y;
		int bDogs=a-x,bCats=b-y;
		a=0;
		if(bDogs<0) a+=bDogs;
		if(bCats<0) a+=bCats;
		a=abs(a);
		if(a>c) cout<<"NO\n";
		else cout<<"YES\n";
	}	
}