/** 
 immortalzodd
 04.06.2024 23:08:45
 polandBallAndForest
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

ll n;
vector<vi> arr;
vector<bool> visited;

void dfs(int x){
	visited[x]=true;
	for(int&y:arr[x]){
		if(!visited[y]) dfs(y);
	}
}

void solve(){
    cin>>n;
    arr.resize(n);
    fr(i,0,n){
    	int x; cin>>x;
    	arr[i].push_back(--x);
    	arr[x].push_back(i);
    }
    visited.assign(n,false);
    ll ans=0;
    fr(i,0,n){
    	if(!visited[i]){
    		dfs(i);
    		ans++;
    	}
    }
    cout<<ans<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}