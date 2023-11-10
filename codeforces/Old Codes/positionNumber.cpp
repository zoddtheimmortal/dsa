#include<iostream>
using namespace std;
int main(){
	int n,a,b; cin>>n>>a>>b;
	int i=b,k=0;
	for(;i<n-a;i++,k++);
	cout<<k<<endl;	
}