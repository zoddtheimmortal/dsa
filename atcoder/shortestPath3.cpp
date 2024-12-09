/** 
 immortalzodd
 16.07.2024 22:54:51
 shortestPath3
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
using ppl = pair<pair<ll,ll>,ll>;

const ll BIG=1e18;

ll n,m;
vector<vector<pll>> arr;

void solve(){
    cin>>n>>m;
    vl hcost(n,0); for(ll&x:hcost) cin>>x;
    arr.resize(n);
    fr(i,0,m){
    	ll f,s,w; cin>>f>>s>>w;
    	arr[--f].push_back({--s,w});
    	arr[s].push_back({f,w});
    }

    vl dist(n,BIG); dist[0]=hcost[0];
    priority_queue<ppl,vector<ppl>,greater<ppl>> pq;
    pq.push({{dist[0],hcost[0]},0LL});

    while(!pq.empty()){
    	auto[coord,v]=pq.top();
    	auto[cdist,head]=coord;
    	pq.pop();
    	if(cdist>dist[v]) continue;

    	for(auto[u,cost]:arr[v]){
    		if(dist[u]>cdist+cost+hcost[u]){
    			pq.push({{dist[u]=cdist+cost+hcost[u],hcost[u]},u});
    		}
    	}
    }

    fr(i,1,n) cout<<dist[i]<<" ";
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