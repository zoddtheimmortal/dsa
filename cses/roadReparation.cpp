/** 
 immortalzodd
 14.06.2024 21:55:56
 roadReparation
**/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pll = pair<ll,ll>;

#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define nL "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)

#define S 0

ll n,m;
vector<vector<pll>> adj;
bool vis[100005];

ll prims(){
	ll mcost=0;
	vl medge(n,INT64_MAX);
	priority_queue<pll> pq;
	pq.push({0,S});
	medge[S]=0;

	int added=0;
	while(added<n){
		if(pq.empty()) return -1;

		auto[cdist,u]=pq.top();
		pq.pop();
		cdist*=-1;
		if(cdist>medge[u]) continue;
		vis[u]=true;
		added++;
		mcost+=cdist;
		for(auto[v,cost]:adj[u]){
			if(!vis[v]&&cost<medge[v]){
				medge[v]=cost;
				pq.push({-cost,v});
			}
		}
	}
	return mcost;
}

void solve(){
    cin>>n>>m;
    adj.resize(n);
    fr(i,0,m){
    	ll f,s,w; cin>>f>>s>>w;
    	adj[--f].push_back({--s,w});
    	adj[s].push_back({f,w});
    }
    ll ans=prims();
    if(ans==-1) cout<<"IMPOSSIBLE"<<nL;
    else cout<<ans<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}