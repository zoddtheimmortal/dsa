/** 
 immortalzodd
 11.04.2024 21:31:02
 numberOfConnectComponents
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

vector<vi> arr;
vector<bool> visited;

void dfs(int x){
	visited[x]=true;

	for(int&y:arr[x]){
		if(!visited[y]) dfs(y);
	}
}

void solve(){
	ll n,m; cin>>n>>m;
	arr.resize(n);

	fr(i,0,m){
		ll f,s; cin>>f>>s;
		arr[--f].push_back(--s);
		arr[s].push_back(f);
	}

	visited=vector<bool>(n,false);

	int ans=0;
	fr(i,0,n){
		if(!visited[i]){
			dfs(i);
			ans++;
		}
	}

	cout<<ans<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}