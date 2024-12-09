/** 
 immortalzodd
 04.07.2024 22:32:34
 shortestPath
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

const ll BIG=1e18;

ll n,m;
vector<vector<pll>> arr;

bool spfa(int s){
	vl dist(n,BIG),cnt(n,0),inq(n,0);
	queue<int> qs;
	dist[s]=0; qs.push(s); inq[s]=1;

	while(!qs.empty()){
		int v=qs.front();
		qs.pop();
		inq[v]=0;
		for(auto[u,cost]:arr[v]){
			if(dist[u]>dist[v]+cost){
				dist[u]=dist[v]+cost;
				if(!inq[u]){
					inq[u]=1;
					qs.push(u);
					cnt[u]++;
					if(cnt[u]>n) return false;
				}
			}
		}
	}
	for(ll&x:dist) cout<<x<<" ";
	cout<<nL;
	return true;
}

void solve(){
	cin>>n>>m;
    arr.resize(n);
    fr(i,0,m){
    	ll f,s,w; cin>>f>>s>>w;
    	arr[--f].push_back({--s,w});
    }
    spfa(0);
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}