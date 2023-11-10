#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--){
		int a,b,c; cin>>a>>b>>c;
		int cTurn=c%2;
		if(a!=b){
			cout<<((a>b)?"First":"Second")<<endl;
		}
		else{
			cout<<((cTurn!=0)?"First":"Second")<<endl;
		}
	}	
}