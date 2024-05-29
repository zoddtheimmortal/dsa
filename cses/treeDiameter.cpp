/** 
 immortalzodd
 09.04.2024 22:12:01
 treeDiameter
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

ll n;
vector<vi> arr;
vi node,dist;
vector<bool> visited;

void dfs(int x){
	visited[x]=true;
	if(dist[x]==0) node[x]=x;

	for(auto&y:arr[x]){
		if(!visited[y]){
			dfs(y);
			if(dist[x]<dist[y]+1){
				dist[x]=dist[y]+1;
				node[x]=node[y];
			}
		}
	}
}

void solve(){
    cin>>n;
    arr.resize(n),node.resize(n);
    dist.resize(n),visited.resize(n);
    fill(all(dist),0); fill(all(visited),false);

    fr(i,0,n-1){
    	ll f,s;
    	cin>>f>>s;
    	arr[--f].push_back(--s);
    	arr[s].push_back(f);
    }

    dfs(0);
    int u=node[0];
    fill(all(dist),0);
    fill(all(visited),false);
    dfs(u);
    cout<<dist[u]<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}