#include<iostream>
#include<cmath>
using namespace std;
int main(){
	//small:15(6s) large:25(10s) medium:20(8s)
	//small 0.4 med 0.4 large 0.4 slice/min
	int t; cin>>t;
	while(t--){
		long long int n; cin>>n;
		long long int x=n/0.4;
		x=((x/5)+1)*5;
		if(n<6) cout<<15<<endl;
		else cout<<x<<endl;
	}
}