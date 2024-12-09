/** 
 immortalzodd
 15.07.2024 10:25:47
 learningLanguages
**/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define nL "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)

ll n,m;
vector<vi> arr;
vi vis;

void dfs(int x){
	vis[x]=1;
	for(int&y:arr[x]){
		if(!vis[y]) dfs(y);
	}
}

void solve(){
	cin>>n>>m;
    arr.resize(n+m);
    int nolang=0;
    fr(i,0,n){
    	ll k; cin>>k;
    	fr(j,0,k){
    		ll s; cin>>s; 
    		arr[i].push_back(n+s-1);
    		arr[n+s-1].push_back(i);
    	}
    	if(arr[i].empty()) nolang++;
    }
    vis.assign(n+m,0);
    ll ans=0;
    fr(i,0,n){
    	if(!vis[i]){
    		dfs(i);
    		ans++;
    	}
    }
    cout<<(nolang==n?n:ans-1)<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}