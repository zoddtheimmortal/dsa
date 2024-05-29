/** 
 immortalzodd
 11.04.2024 18:15:34
 flights
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

vi dist;
vector<vector<pair<int,int>>> arr;
ll n,m;

void djikstra(int src){
	priority_queue<pair<int,int>> pq;

	pq.push({0,src});
	dist[src]=0;

	while(!pq.empty()){
		int v=pq.top().second;
		pq.pop();

		for(auto&x:arr[v]){
			if(dist[x.first]>dist[v]+x.second){
				dist[x.first]=dist[v]+x.second;
				pq.push({-dist[x.first],x.first});
			}
		}
	}
}

void solve(){
	cin>>n>>m;
	arr.resize(n);

    fr(i,0,m){
    	ll f,s,w; cin>>f>>s>>w;
    	arr[--f].push_back({--s,w});
    }

    dist=vi(n,INT_MAX);
    djikstra(0);

    for(int&x:dist) cout<<x<<" ";
    cout<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}