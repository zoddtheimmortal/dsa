/** 
 immortalzodd
 14.06.2024 09:45:46
 flightRoutes
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

ll n,m,k;
vector<vector<pll>> arr;

void solve(){
    cin>>n>>m>>k;
    arr.resize(n);
    fr(i,0,m){
    	ll f,s,w; cin>>f>>s>>w;
    	arr[--f].push_back({--s,w});
    }
    priority_queue<ll> best[n];
    priority_queue<pll,vector<pll>,greater<pll>> pq;
    best[0].push(0); pq.push({0,0});

    while(!pq.empty()){
    	auto[cdist,u]=pq.top();
    	pq.pop();
    	if(cdist>best[u].top()) continue;
    	for(auto[v,cost]:arr[u]){
    		if(best[v].size()<k){
    			best[v].push(cdist+cost);
    			pq.push({cdist+cost,v});
    		}
    		else if(best[v].top()>cdist+cost){
    			best[v].pop();
    			best[v].push(cdist+cost);
    			pq.push({cdist+cost,v});
    		}
    	}
    }
    vl ans;
    while(!best[n-1].empty()){
    	ans.push_back(best[n-1].top());
    	best[n-1].pop();
    }
    reverse(all(ans));
    for(ll&x:ans) cout<<x<<" ";
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