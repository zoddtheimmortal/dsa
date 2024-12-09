/** 
 immortalzodd
 16.07.2024 23:26:03
 treeAndHamiltonPath2
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

using pll = pair<ll,ll>;

ll n;
vector<vector<pll>> arr;
vl dist;

int dfs(ll x,ll p,ll d){
	dist[x]=d;
	int opt=-1;
	for(auto[y,cost]:arr[x]){
		if(y!=p){
			int z=dfs(y,x,d+cost);
			if(opt==-1||dist[z]>dist[opt]) opt=z;
		}
	}
	return (opt==-1?x:opt);
}

void solve(){
    ll n; cin>>n;
    arr.resize(n);
    ll circsum=0;
    fr(i,0,n-1){
    	ll f,s,w; cin>>f>>s>>w;
    	arr[--f].push_back({--s,w});
    	arr[s].push_back({f,w});
    	circsum+=w;
    }
    dist=vl(n,0);
    int u=dfs(0,0,0);
    dist=vl(n,0);
    int v=dfs(u,u,0);

    cout<<2*circsum-dist[v]<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}