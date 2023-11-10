#include<bits/stdc++.h>
using namespace std;
int parseArray(int a[],int n);
int evenArray(int a[],int n);
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int a[n]; for(int&x:a) cin>>x;
		int ans=parseArray(a,n);
		cout<<(ans?"YES":"NO")<<'\n';
	}	
}

int parseArray(int a[],int n){
	if(!evenArray(a,n)){
		for(int i=(a[0]%2==0?1:0);i<n;i+=2) a[i]+=1;
		if(!evenArray(a,n)){
			for(int i=(a[0]%2==0?1:0);i<n;i+=2) a[i]+=1;
			return evenArray(a,n);
		}
		return evenArray(a,n);
	}
	else return 1;
}

int evenArray(int a[],int n){
	for(int i=0;i<n;i++){
		if(a[i]%2!=0) return 0;
	}
	return 1;
}