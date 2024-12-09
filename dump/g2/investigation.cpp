/** 
 immortalzodd
 17.08.2024 13:53:36
 investigation
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
const int MXN=1e5+5;
const ll BIG=1e18;
const int MOD=1e9+7;
vector<pll> arr[MXN];

void solve(){
    cin>>n>>m;
    fr(i,0,m){
    	ll f,s,w; cin>>f>>s>>w;
    	arr[--f].push_back({--s,w});
    }

    vl max_route(n,0),min_route(n,0),dist(n,BIG),cnt(n,0);
    cnt[0]=1;
    dist[0]=0;

    priority_queue<pll,vector<pll>,greater<pll>> pq;
    pq.push({0,0});

    while(!pq.empty()){
    	auto[cdist,v]=pq.top();
    	pq.pop();

    	for(auto[u,cost]:arr[v]){
    		if(dist[u]>cdist+cost){
    			dist[u]=cdist+cost;
    			cnt[u]=cnt[v];
    			max_route[u]=1+max_route[v];
    			min_route[u]=1+min_route[v];
    			pq.push({dist[u],u});
    		}
    		else if(dist[u]==cdist+cost){
    			cnt[u]+=cnt[v];
    			cnt[u]%=MOD;
    			max_route[u]=max(max_route[u],1+max_route[v]);
    			min_route[u]=min(min_route[u],1+min_route[v]);
    		}
    	}
    }

    cout<<dist[n-1]<<" "<<cnt[n-1]<<" "<<min_route[n-1]<<" "<<max_route[n-1]<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}