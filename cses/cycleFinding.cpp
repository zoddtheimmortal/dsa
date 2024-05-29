/** 
 immortalzodd
 03.05.2024 13:33:22
 cycleFinding
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

#define S 0

struct edge{
	int from,to;
	ll w=INT_MAX;
};

ll n,m;
vector<edge> edges;
vl dist,parent;

void bellman(int src){
	dist.assign(n,INT_MAX);
	parent.assign(n,0);

	dist[src]=0;
	int last_updated=-1;

	fr(i,0,n){
		last_updated=-1;
		for(edge&e:edges){
			if(dist[e.from]+e.w<dist[e.to]){
				dist[e.to]=dist[e.from]+e.w;
				parent[e.to]=e.from;
				last_updated=e.to;
			}
		}
	}

	if(last_updated==-1){
		cout<<"NO"<<nL;
	}
	else{
		vi cycle;
		fr(i,0,n-1) last_updated=parent[last_updated];
		for(int x=last_updated;;x=parent[x]){
			cycle.push_back(x);
			if(x==last_updated&&cycle.size()>1) break;
		}

		reverse(all(cycle));
		cout<<"YES"<<nL;
		for(int&x:cycle) cout<<x+1<<" ";
		cout<<nL;
	}
}

void solve(){
    cin>>n>>m;
    edges.resize(m);

    for(edge&e:edges){
    	int f,s,w; cin>>f>>s>>w;
    	e.from=--f,e.to=--s,e.w=w;
    }

    bellman(S);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}