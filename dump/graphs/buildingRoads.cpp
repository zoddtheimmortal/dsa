/** 
 immortalzodd
 29.06.2024 11:18:27
 buildingRoads
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
	arr.resize(n);
	fr(i,0,m){
		ll f,s; cin>>f>>s;
		arr[--f].push_back(--s);
		arr[s].push_back(f);
	}
	vis.assign(n,0);
	int prev=0;
	dfs(0);
	vector<pair<int,int>> edges;

	fr(i,1,n){
		if(!vis[i]){
			dfs(i);
			edges.push_back({prev,i});
			prev=i;
		}
	}

	cout<<edges.size()<<nL;
	for(pair<int,int>&e:edges){
		cout<<e.first+1<<" "<<e.second+1<<nL;
	}
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}