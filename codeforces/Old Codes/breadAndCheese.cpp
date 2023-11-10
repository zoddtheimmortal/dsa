#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--){
		int b,c,h; cin>>b>>c>>h;
		cout<<3+2*min(c+h-1,b-2)<<endl;
	}	
}