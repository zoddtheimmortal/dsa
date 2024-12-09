/** 
 immortalzodd
 25.06.2024 15:21:57
 rumor
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

ll n,m;
vector<vi> arr;
vi gold,vis;

int dfs(int x,int prev){
	int cost=min(prev,gold[x]);
	vis[x]=1;
	for(int&y:arr[x]){
		if(!vis[y]){
			int k=dfs(y,cost);
			cost=min(cost,k);
		}
	}
	return cost;
}

void solve(){
    cin>>n>>m;
    arr=vector<vi>(n); gold.assign(n,0); vis.assign(n,0);
    for(int&x:gold) cin>>x;
    fr(i,0,m){
    	ll f,s; cin>>f>>s;
    	arr[--f].push_back(--s);
    	arr[s].push_back(f);
    }

    ll ans=0;
    fr(i,0,n){
    	if(!vis[i]){
    		ans+=dfs(i,INT_MAX);
    	}
    }
    cout<<ans<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}