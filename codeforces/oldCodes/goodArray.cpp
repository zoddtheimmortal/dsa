#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<int> a(n);
		long long s=0;
		for(int& x:a){
			cin>>x;
			s+=x;
		}
		int c=count(a.begin(),a.end(),1);
		cout<<(n>1&&(c+2*n-s<=n)?"YES":"NO")<<"\n";
	}
}