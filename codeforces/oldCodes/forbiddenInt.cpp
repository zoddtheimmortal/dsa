#include<bits/stdc++.h>
using namespace std;
int main(){
	// ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--){
		int n,k,x,p=0; cin>>n>>k>>x;
		int arr[n]={0};
		for(int i=k;i>0;i--){
			if(i!=x){
				if(n%i!=x){
					for(int j=0;j<n/i;j++){
						arr[p++]=i;
					}
					if(n%i==0) break;
					else{
						arr[p++]=n%i;
					}
					break;
				}
				else if(n%i==x && x!=1){
					for(int j=0;j<n/i;j++){
						arr[p++]=n/i;
					}
					for(int j=0;j<x;j++){
						arr[p++]=1;
					}
					break;
				}
			}
		}
		if(p!=0){
			cout<<"YES\n"<<p<<endl;
			for(int j=0;j<p;j++){
				cout<<arr[j]<<" ";
			}
			cout<<"\n";
		}
		else{
			cout<<"NO\n";
		}
	}	
}