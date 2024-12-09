/** 
 immortalzodd
 14.07.2024 19:52:24
 bicycles
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
using ppl = pair<ll,pair<ll,ll>>;

const ll BIG=1e18;

void solve(){
    ll n,m; cin>>n>>m;
    vector<vector<pll>> arr(n);
    fr(i,0,m){
    	ll f,s,w; cin>>f>>s>>w;
    	arr[--f].push_back({--s,w});
    	arr[s].push_back({f,w});
    }

    vi s(n,0); for(int&x:s) cin>>x;

    vector<vl> dist(n,vl(1001,BIG));
    vector<vl> vis(n,vl(1001,0));
    dist[0][s[0]]=0;
    priority_queue<ppl> pq;
    pq.push({0,{0,s[0]}});

    while(!pq.empty()){
    	auto[v,k]=pq.top().second;
    	pq.pop();
    	if(vis[v][k]||dist[v][k]>=BIG) continue;
    	vis[v][k]=1;

    	for(auto[u,w]:arr[v]){
    		ll c=min<ll>(k,s[u]);
    		if(dist[u][c]>1LL*w*k+dist[v][k]){
    			dist[u][c]=1LL*w*k+dist[v][k];
    			pq.push({-dist[u][c],{u,c}});
    		}
    	}
    }

    ll ans=BIG;
    fr(i,0,1001) ans=min(ans,dist[n-1][i]);
    cout<<ans<<nL;
}

int main(){
    fast_io;
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}