/** 
 immortalzodd
 29.05.2024 22:38:12
 dfs
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
vector<bool> visited;

void dfs(int x){
	visited[x]=true;
	cout<<x<<" ";
	for(int&y:arr[x]){
		if(!visited[y]) dfs(y);
	}
}

void solve(){
	cin>>n>>m;
	arr.resize(n);
	fr(i,0,m){
		ll f,s; cin>>f>>s;
		arr[--f].push_back(--s);
		arr[s].push_back(f);
	}
	visited.assign(n,false);
	dfs(0);
	cout<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}