/** 
 immortalzodd
 29.06.2024 16:27:05
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

ll n,m;
vector<vector<pll>> arr,revarr;
const ll BIG=1e18;

vl djiksta(int s,vector<vector<pll>>&arr){
	vl dist(n,BIG);
	dist[s]=0;
	priority_queue<pll,vector<pll>,greater<pll>> pq;
	pq.push({0,s});

	while(!pq.empty()){
		auto[cdist,v]=pq.top();
		pq.pop();
		if(cdist!=dist[v]) continue;

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
    arr.resize(n);
    revarr.resize(n);
    fr(i,0,m){
    	ll f,s,w; cin>>f>>s>>w;
    	arr[--f].push_back({--s,w});
    	revarr[s].push_back({f,w});
    }
    vl d1=djiksta(0,arr);
    vl d2=djiksta(n-1,revarr);

    ll ans=BIG;
    fr(v,0,n){
    	for(auto[u,w]:arr[v]){
    		ans=min(ans,d1[v]+d2[u]+w/2);
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