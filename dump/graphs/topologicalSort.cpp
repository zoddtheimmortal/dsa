/** 
 immortalzodd
 29.05.2024 22:40:50
 topologicalSort
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
vi order;

void topoSort(){

}

void dfs(int x){
	visited[x]=true;
	for(int&y:arr[x]){
		if(!visited[y]) dfs(y);
	}
	order.push_back(x);
}

void solve(){
	cin>>n>>m;
	arr.resize(n);
	fr(i,0,m){
		ll f,s; cin>>f>>s;
		arr[--f].push_back(--s);
	}
	visited.assign(n,false);
	dfs(0);
	// topoSort();
	reverse(all(order));
	for(int&x:order) cout<<x+1<<" ";
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