/** 
 immortalzodd
 12.06.2024 21:46:39
 highScore
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

const ll N=2501;
const ll MAX=1e16;

struct edge{
	ll u,v,w;
};

ll n,m;
ll dist[N];
bool vis[N],vis2[N];
vi adj[N],adj2[N];

void dfs(int x){
	vis[x]=true;
	for(int&y:adj[x]){
		if(!vis[x]) dfs(y);
	}
}

void dfs2(int x){
	vis2[x]=true;
	for(int&y:adj2[x]){
		if(!vis2[x]) dfs(y);
	}
}

void solve(){
    cin>>n>>m;
    vector<edge> arr(m);
    fr(i,0,m){
    	ll f,s,w; cin>>f>>s>>w;
    	arr[i]={--f,--s,-w};
    	adj[f].push_back(s);
    	adj2[s].push_back(f);
    }
    dfs(0); dfs2(n-1);

    vl dis(n,MAX);
    dis[0]=0;
    fr(i,0,n){
    	for(edge&e:arr){
    		if(dis[e.v]>dis[e.u]+e.w){
    			dis[e.v]=dis[e.u]+e.w;
    			if(i==n-1&&vis[e.v]&&vis2[e.v]){
    				cout<<-1<<nL;
    				return;
    			}
    		}
    	}
    }
    cout<<-dis[n-1]<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}