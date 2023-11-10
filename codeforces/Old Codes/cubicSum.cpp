#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		long long int x; cin>>x;
		long long int a=cbrt(x),b=cbrt(x-pow(a,3));
		long long int sum= pow(a,3)+pow(b,3);
		cout<<a<<" "<<b<<endl;
		if(sum==x && a>0 && b>0) cout<<"Yes\n";
		else{
			long long int diff=x-sum;
			b+=cbrt(diff);
			cout<<a<<" "<<b<<endl;
		}
	}
}