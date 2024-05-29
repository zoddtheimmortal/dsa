/** 
 immortalzodd
 14.04.2024 23:02:40
 longestFlightRoute
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

vector<vi> arr,back_edge;
vi top_sort;
vector<bool> visited;

void dfs(int x){
	visited[x]=true;
	for(int&y:arr[x]){
		if(!visited[y]) dfs(y);
	}
	top_sort.push_back(x);
}

void solve(){
    ll n,m;
    cin>>n>>m;
    arr.resize(n); back_edge.resize(n);
    vi path(n,INT_MIN),parent(n,-1);

    fr(i,0,m){
    	ll f,s; cin>>f>>s;
    	arr[--f].push_back(--s);
    	back_edge[s].push_back(f);
    }
    visited.assign(n,false);

    dfs(0);
    for(int&x:top_sort){
    	for(int&y:back_edge[x]){
    		
    	}
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}