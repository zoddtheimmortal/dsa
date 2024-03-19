#include<iostream>
using namespace std;
#define max(a,b) a>b?a:b
int opCount(int a,int b,int n,int k);
int main(){
	int t; cin>>t;
	while(t--){
		int a,b,n; cin>>a>>b>>n;
		cout<<opCount(a,b,n,0)<<"\n";
	}	
}

int opCount(int a,int b,int n,int k){
	if(a>n || b>n) return k;
	else if(n-a>n-b){
		opCount(a+b,b,n,k+1);
	}
	else{
		opCount(a,b+a,n,k+1);
	}
}