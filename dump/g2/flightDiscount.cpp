/** 
 immortalzodd
 17.08.2024 14:12:52
 flightDiscount
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
using tll = tuple<ll,ll,ll>;

ll n,m;
const int MXN=1e5+5;
const ll BIG=1e18;
vector<pll> arr[MXN],rarr[MXN];
vector<tll> edges;

vl djikstra(ll s,vector<pll> arr[]){
	vl dist(n,BIG);
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
    edges.resize(m);
    fr(i,0,m){
    	ll f,s,w; cin>>f>>s>>w;
    	--f; --s;
    	arr[f].push_back({s,w});
    	rarr[s].push_back({f,w});
    	edges.push_back({f,s,w});
    }

    vl d1=djikstra(0,arr);
    vl d2=djikstra(n-1,rarr);

    ll ans=BIG;
    for(auto[u,v,w]:edges){
    	ans=min(ans,d1[u]+d2[v]+w/2);
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