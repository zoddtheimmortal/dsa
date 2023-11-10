#include<iostream>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n,a,b,c,d; cin>>n>>a>>b>>c>>d;
		int minCase=n*(a-b),maxCase=n*(a+b);
		if((c-d<=minCase && minCase<=c+d)||(c-d<=maxCase && maxCase<=c+d)){
			cout<<"Yes\n";
		}
		else{
			cout<<"No\n";
		}
	}
}