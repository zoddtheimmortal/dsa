/** 
 immortalzodd
 08.07.2024 16:00:45
 gridDjikstra
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

using ppl = pair<ll,pair<ll,ll>>;

const ll BIG=1e18;
int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

void solve(){
	ll n; cin>>n;
    vector<vl> grid(n,vl(n,0));
    fr(i,0,n){
    	fr(j,0,n) cin>>grid[i][j];
    }

    vector<vl> dist(n,vl(n,BIG));
    dist[0][0]=0;
    priority_queue<ppl,vector<ppl>,greater<ppl>> pq;
    pq.push({0,{0,0}});

    while(!pq.empty()){
    	auto[cdist,coord]=pq.top();
    	auto[r,c]=coord;
    	pq.pop();
    	if(cdist!=dist[r][c]) continue;

    	fr(i,0,4){
    		ll p=r+dx[i],q=c+dy[i];
    		if(p<0||p>=n||q<0||q>=n) continue;
    		ll cost=grid[p][q];
    		if(dist[p][q]>cdist+cost){
    			pq.push({dist[p][q]=cdist+cost,{p,q}});
    		}
    	}
    }
    cout<<dist[n-1][n-1]<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}