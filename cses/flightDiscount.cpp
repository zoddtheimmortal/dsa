/** 
 immortalzodd
 10.06.2024 19:44:36
 flightDiscount
**/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<ll,ll>;

#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define nL "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)

ll n,m;
vector<vector<pii>> grid,rev_grid;

vl djikstra(ll x,vector<vector<pii>>& arr){
	vl dist(n,INT64_MAX);
	dist[x]=0;
	priority_queue<pii> pq;
	pq.push({0,x});
	while(!pq.empty()){
		auto [cdist,v]=pq.top();
		cdist*=-1;
		pq.pop();
		if(cdist!=dist[v]) continue;
		for(auto[u,cost]:arr[v]){
			if(cdist+cost<dist[u]){
				dist[u]=cdist+cost;
				pq.push({-(cdist+cost),u});
			}
		}
	}
	return dist;
}

void solve(){
    cin>>n>>m;
    grid.resize(n); rev_grid.resize(n);
    fr(i,0,m){
    	ll f,s,w; cin>>f>>s>>w;
    	grid[--f].push_back({--s,w});
    	rev_grid[s].push_back({f,w});
    }

    vl dist=djikstra(0,grid);
    vl rdist=djikstra(n-1,rev_grid);
    ll ans=INT64_MAX;
    fr(v,0,n){
    	for(auto[u,cost]:grid[v]){
    		if(dist[v]==INT64_MAX||rdist[u]==INT64_MAX) continue;
    		ans=min(ans,dist[v]+cost/2+rdist[u]);
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