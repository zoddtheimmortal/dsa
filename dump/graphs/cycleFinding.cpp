/** 
 immortalzodd
 29.06.2024 21:59:00
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
#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)

struct edge{
	ll a,b,c;
};

const ll BIG=1e18;

ll n,m;
vector<edge> arr;

void solve(){
    cin>>n>>m;
    arr.resize(m);
    fr(i,0,m){
    	ll f,s,w; cin>>f>>s>>w;
    	arr[i]=(edge){--f,--s,w};
    }
    vl dist(n,BIG),parent(n,0);
    dist[0]=0;

    ll lastUpdated=-1;
    fr(i,0,n){
    	lastUpdated=-1;
    	for(edge&e:arr){
    		if(dist[e.a]+e.c<dist[e.b]){
    			dist[e.b]=dist[e.a]+e.c;
    			lastUpdated=e.b;
    			parent[e.b]=e.a;
    		}
    	}
    }
    if(lastUpdated==-1){
    	cout<<"NO"<<nL;
    	return;
    }

    vl cycle;
    fr(i,0,n-1) lastUpdated=parent[lastUpdated];
    for(ll x=lastUpdated;;x=parent[x]){
    	cycle.push_back(x);
    	if(x==lastUpdated&&cycle.size()>1) break;
    }
    reverse(all(cycle));
    cout<<"YES"<<nL;
    for(ll&x:cycle) cout<<x+1<<" ";
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