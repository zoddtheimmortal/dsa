/** 
 immortalZodd
 05.02.2024 12:07:24
 closingTheFarm
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

ll nodes=0;

void dfs(vi arr[],ll sv,vector<bool> &visited,vector<bool> &closed){
	if(visited[sv]||closed[sv]) return;

	visited[sv]=true;
	nodes++;

	for(auto&x:arr[sv]){
		dfs(arr,x,visited,closed);
	}
}

void solve(){
	freopen("closing.in","r",stdin);
	freopen("closing.out","w",stdout);
    ll n,m; cin>>n>>m;
    vi arr[n];
    while(m--){
    	ll f,s; cin>>f>>s;
    	arr[--f].push_back(--s);
    	arr[s].push_back(f);
    }

    vi order(n,0);
    fr(i,0,n){
    	ll x; cin>>x;
    	order[i]=x-1;
    }

    vector<bool> visited(n,false),closed(n,false);

    dfs(arr,0,visited,closed);
    cout<<((nodes==n)?"YES":"NO")<<nL;

    fr(i,0,n-1){
    	fill(all(visited),false);
    	closed[order[i]]=true;
    	nodes=0;

    	dfs(arr,order[n-1],visited,closed);
    	cout<<((nodes==n-i-1)?"YES":"NO")<<nL;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}