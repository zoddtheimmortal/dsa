/** 
 immortalzodd
 17.08.2024 11:22:16
 shortestRouteI
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

ll n,m;
const int MXN=2e5+5;
const ll BIG=1e18;
vector<pll> arr[MXN];

vl djikstra(int s){
	vl dist(n+1,BIG);
	dist[s]=0;

	priority_queue<pll,vector<pll>,greater<pll>> pq;
	pq.push({0,s});

	while(!pq.empty()){
		auto[cdist,v]=pq.top();
		pq.pop();
		if(cdist>dist[v]) continue;

		for(auto[u,cost]:arr[v]){
			if(dist[u]>cdist+cost){
				pq.push({dist[u]=cdist+cost,u});
			}
		}
	}

	return dist;
}

void solve(){
    cin>>n>>m;
    fr(i,0,m){
    	ll f,s,w; cin>>f>>s>>w;
    	arr[f].push_back({s,w});
    }

    vl dist=djikstra(1);
    fr(i,1,n+1) cout<<dist[i]<<" ";
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