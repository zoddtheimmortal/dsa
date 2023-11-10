#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

#define pb push_back
#define v(x) vector<x>
#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define rep(i,arr) for(auto i:arr)
#define nL "\n"

void markDec(vi arr,int n,int sv,v(bool) &visited){
	visited[sv]=true;
	queue<int> qs;
	qs.push(arr[sv]);
	while(!qs.empty()){
		int vertex=qs.front();
		qs.pop();
		fr(i,sv+1,n){
			if(!visited[i] && arr[i]>vertex){
				qs.push(arr[i]);
				visited[i]=true;
			}
		}
	}
}

int findRounds(vi arr,int n){
	v(bool) visited(n,false);
	ll count=0;
	fr(i,0,n){
		if(!visited[i]){
			count++;
			markDec(arr,n,i,visited);
		}
	}
	return count;
}

void solve(){
     ll n; cin>>n;
     vi arr(n,0);
     fr(i,0,n) cin>>arr[i];
     cout<<findRounds(arr,n)<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}