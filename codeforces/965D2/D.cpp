/** 
 immortalzodd
 11.08.2024 09:35:29
 D
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

using pii = pair<int,int>;

void solve(){
	ll n,m; cin>>n>>m;
	vector<vi> arr(n);
	vector<pii> ed;
	fr(i,1,n){
		arr[i-1].push_back(i);
	}    
	fr(i,0,m){
		ll f,s; cin>>f>>s;
		arr[--f].push_back(--s);
		ed.push_back({f,s});
	}

	vi dist(n,-1);
	dist[0]=0;
	queue<int> qs;
	qs.push(0);

	while(!qs.empty()){
		int v=qs.front();
		qs.pop();
		for(int&u:arr[v]){
			if(dist[u]==-1){
				qs.push(u);
				dist[u]=1+dist[v];
			}
		}
	}

	vi sum(n+1,0);
	for(auto[u,v]:ed){
		int t=1+dist[u];
		int l=u+1,r=v-t-1;
		if(l<=r) sum[l]++,sum[r+1]--;
	}

	fr(i,0,n-1){
		sum[i+1]+=sum[i];
		if(sum[i]) cout<<0;
		else cout<<1;
	}
	cout<<nL;
}

int main(){
    fast_io;
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}