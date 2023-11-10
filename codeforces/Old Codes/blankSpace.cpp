#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++) cin>>a[i];
		int max=0,holder=0,flag=0;
		for(int i=0;i<n;i++){
			if(i<n-1 &&a[i]==0 && a[i+1]==0){
				holder++;
				if(holder>max) max=holder;
			}
			else if(a[i]==0){
				flag=1;
			}
			else{
				holder=0;
			}
		}
		cout<<(flag==0?max:max+1)<<"\n";
	}	
}