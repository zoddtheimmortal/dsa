#include<bits/stdc++.h>
using namespace std;
int main(){
	// ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--){
		int x,k; cin>>x>>k;
		int arr[201]={0}; int p=0;
		for(int i=x;i>0&&x>0;i--){
			if(i%k!=0){
				arr[p++]=i;
				int temp=i;
				i=x-i+1;
				x=x-temp;
			}
		}
		cout<<p<<endl;
		for(int i=0;i<p;i++) cout<<arr[i]<<" ";
		cout<<"\n";
	}
}