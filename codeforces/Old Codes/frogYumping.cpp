#include<iostream>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		long long int a,b,k,coord=0;
		cin>>a>>b>>k;
		coord=(k/2)*(a-b);
		if(k%2==0){
			cout<<coord<<endl;
		}
		else{
			cout<<coord+a<<endl;
		}
	}	
}