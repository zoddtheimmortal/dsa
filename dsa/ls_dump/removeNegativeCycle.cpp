/** 
 immortalzodd
 08.05.2024 10:12:29
 removeNegativeCycle
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
	int from,to,w;
};

ll n,m;
vector<edge> arr;
vi dist;

void bellman(int src){
	dist.assign(n,INT_MAX);
	int last_node=-1;
	dist[src]=0;

	fr(i,0,n){
		last_node=-1;
		for(edge&e:arr){
			if(dist[e.to]>dist[e.from]+e.w){
				dist[e.to]=dist[e.from]+e.w;
				last_node=e.to;
			}
		}
	}

	if(last_node!=-1){
		for(edge&e:arr) e.w++;
		bellman(src);
	}
}

void solve(){
    cin>>n>>m;
    arr.resize(m);
    for(edge&e:arr){
    	int f,s,w; cin>>f>>s>>w;
    	e.from=--f,e.to=--s,e.w=w;
    }

    bellman(S);

    for(int&x:dist){
    	if(x==INT_MAX) cout<<"INF"<<" ";
    	else cout<<x<<" ";
    }
    cout<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}