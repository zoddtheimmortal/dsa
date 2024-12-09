/** 
 immortalzodd
 29.06.2024 10:44:16
 shortestPathI
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
vector<vector<pll>> arr;

void solve(){
    cin>>n>>m;
    arr.resize(n);
    fr(i,0,m){
    	ll f,s,w; cin>>f>>s>>w;
    	arr[--f].push_back({--s,w});
    }

    vl dist(n,INT64_MAX);
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    pq.push({0,0});
    dist[0]=0;

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
    for(ll&x:dist) cout<<x<<" ";
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