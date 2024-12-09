/** 
 immortalzodd
 25.07.2024 09:45:17
 distinctColors
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

const int MXN=2e5+5;
ll n;
vi arr[MXN];
int dist_colors[MXN];
set<int> colors[MXN];

void dfs(int x,int p){
	for(int&y:arr[x]){
		if(y!=p){
			dfs(y,x);
			if(colors[x].size()<colors[y].size()) swap(colors[x],colors[y]);
			for(int i:colors[y]) colors[x].insert(i);
		}
	}
	dist_colors[x]=colors[x].size();
}

void solve(){
    cin>>n;
    fr(i,1,n+1){
    	int x; cin>>x;
    	colors[i].insert(x);
    }

    fr(i,0,n-1){
    	ll f,s; cin>>f>>s;
    	arr[f].push_back(s);
    	arr[s].push_back(f);
    }

    dfs(1,0);

    fr(i,1,n+1) cout<<dist_colors[i]<<" ";
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