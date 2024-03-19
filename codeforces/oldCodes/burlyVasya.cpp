#include<iostream>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int a,b; cin>>a>>b;
		cout<<maxAmount(a,b,0)<<endl;
	}	
}

int maxAmount(int a,int b,int amt){
	if(amt+1>(a+2*b)||())
}