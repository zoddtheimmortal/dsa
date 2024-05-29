/** 
 immortalzodd
 03.05.2024 18:37:19
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

ll n,m;
vector<vector<pair<int,int>>> arr;
vl dist,cost;

void djikstra(int src){
	dist.assign(n,LLONG_MAX);
	cost.assign(n,LLONG_MIN);
	using T=pair<ll,int>;
	priority_queue<T,vector<T>,greater<T>> pq;

	dist[src]=0;
	pq.push({0,src});

	while(!pq.empty()){
		const auto [cdist,node]=pq.top();
		pq.pop();
		if(cdist!=dist[node]) continue;
		for(auto&p:arr[node]){
			if(cdist+p.second<dist[p.first]){
				dist[p.first]=cdist+p.second;
				cost[p.first]=max(cost[p.first],dist[p.first]);
				pq.push({dist[p.first],p.first});
			}
		}
	}
}

void solve(){
    cin>>n>>m;
    arr.resize(n);

	fr(i,0,m){
    	int f,s,w; cin>>f>>s>>w;
    	arr[--f].push_back({--s,w});
    }

    djikstra(0);
    for(auto&x:dist) cout<<x<<" ";
    cout<<nL;
	for(auto&x:cost) cout<<x<<" ";
    cout<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}