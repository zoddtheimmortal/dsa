/** 
 immortalzodd
 29.06.2024 17:24:48
 flightRoutes
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

    pq.push({0,0});
    best[0].push(0);

    while(!pq.empty()){
    	auto[cdist,v]=pq.top();
    	pq.pop();
    	if(cdist>best[v].top()) continue;
    	for(auto[u,cost]:arr[v]){
    		if((ll)best[u].size()<k){
    			best[u].push(cost+cdist);
    			pq.push({cdist+cost,u});
    		}
    		else if(cdist+cost<best[u].top()){
    			best[u].pop();
    			best[u].push(cost+cdist);
    			pq.push({cdist+cost,u});
    		}
    	}
    }

    vl price;
    while(!best[n-1].empty()){
    	price.push_back(best[n-1].top());
    	best[n-1].pop();
    }
    reverse(all(price));
    for(ll&x:price) cout<<x<<" ";
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