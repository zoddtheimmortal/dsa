#include<iostream>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int n,k; cin>>n>>k;
		int noOne=0,noMinus=0;
		if(k<n){
			cout<<"YES\n";
			noOne=k+1; noMinus=n-k-1;
			for(int i=0;i<noOne;i++) cout<<"1 ";
			for(int i=0;i<noMinus;i++) cout<<"-1 ";
			cout<<endl;
		}
		else{
			cout<<"NO\n";
		}
	}	
}