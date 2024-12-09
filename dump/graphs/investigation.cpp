/** 
 immortalzodd
 29.06.2024 20:47:52
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

const int MOD=1e9+7;
const ll BIG=1e18;
ll n,m;
vector<vector<pll>> arr;

void solve(){
    cin>>n>>m;
    arr.resize(n);
    fr(i,0,m){
    	ll f,s,w; cin>>f>>s>>w;
    	arr[--f].push_back({--s,w});
    }

    vl dist(n,BIG); dist[0]=0;
    vl num(n,0);
    vl minf(n,0);
    vl maxf(n,0); 
    num[0]=1;

    priority_queue<pll,vector<pll>,greater<pll>> pq;
    pq.push({0,0});

    while(!pq.empty()){
    	auto[cdist,v]=pq.top();
    	pq.pop();

    	if(cdist!=dist[v]) continue;

    	for(auto[u,cost]:arr[v]){
    		if(dist[u]>cdist+cost){
    			num[u]=num[v];
    			minf[u]=minf[v]+1;
    			maxf[u]=maxf[v]+1;
    			pq.push({dist[u]=cdist+cost,u});
    		}
    		else if(dist[u]==cdist+cost){
    			num[u]+=num[v];
    			num[u]%=MOD;
    			minf[u]=min(minf[u],1+minf[v]);
    			maxf[u]=max(maxf[u],1+maxf[v]);
    		}
    	}
    }
    cout<<dist[n-1]<<" "<<num[n-1]<<" "<<minf[n-1]<<" "<<maxf[n-1]<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}