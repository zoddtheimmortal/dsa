/** 
 immortalzodd
 11.06.2024 21:53:44
 investigation
**/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pli = pair<ll,int>;
using pii = pair<int,int>;

#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define nL "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)

unsigned int MOD=1e9+7;

ll n,m;
vector<vector<pii>> arr;
vl dist,maxf,minf,num;
vector<bool> vis;

void djikstra(int x){
	dist.assign(n,INT64_MAX);
	maxf.assign(n,0);
	minf.assign(n,0);
	num.assign(n,0);
	vis.assign(n,false);

	dist[x]=0; num[x]=1;
	priority_queue<pli> pq;
	pq.push({0LL,x});

	while(!pq.empty()){
		auto [cdist,v]=pq.top();
		pq.pop();

		if(vis[v]) continue;
		vis[v]=true;
		for(auto[u,cost]:arr[v]){
			ll new_cost=dist[v]+cost;
			if(new_cost<dist[u]){
				minf[u]=minf[v]+1;
				maxf[u]=maxf[v]+1;
				num[u]=num[v];
				dist[u]=new_cost;
				pq.push({-new_cost,u});
			}
			else if(new_cost==dist[u]){
				num[u]=(num[u]+num[v])%MOD;
				minf[u]=min(minf[u],minf[v]+1);
				maxf[u]=max(maxf[u],maxf[v]+1);
			}
		}
	}

}

void solve(){
	cin>>n>>m;
	arr=vector<vector<pii>>(n);
	fr(i,0,m){
		ll f,s,w; cin>>f>>s>>w;
		arr[--f].push_back({--s,w});
	}
	djikstra(0);
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