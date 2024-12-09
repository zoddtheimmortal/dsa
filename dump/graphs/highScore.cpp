/** 
 immortalzodd
 29.06.2024 16:10:36
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
    	arr[i]=(edge){--f,--s,-w};
    }
    int lastUpdated=-1;
    vl dist(n,BIG);
    dist[0]=0;
    fr(i,0,n){
    	lastUpdated=-1;
    	for(edge&e:arr){
    		if(dist[e.a]+e.c<dist[e.b]){
    			dist[e.b]=dist[e.a]+e.c;
    			lastUpdated=e.b;
    		}
    	}
    }
    if(lastUpdated!=-1){
    	cout<<-1<<nL;
    	return;
    }
    cout<<-dist[n-1]<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}