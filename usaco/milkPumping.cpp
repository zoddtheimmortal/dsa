/** 
 immortalzodd
 10.06.2024 22:05:51
 milkPumping
**/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int,int>;

#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define nL "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)

struct edge{
	int a,b,c,f;
};

ll n,m;
vector<edge> arr;
vi flows;

int bellman(int flow){
	vector<ll> dist(n,INT_MAX);
    dist[0]=0;
    fr(i,0,n-1){
    	for(edge&e:arr){
    		if(e.f<flow) continue;
    		if(dist[e.a]<INT_MAX&&dist[e.b]>dist[e.a]+e.c){
    			dist[e.b]=dist[e.a]+e.c;
    		}
    	}
    }
    return (dist[n-1]<INT_MAX?dist[n-1]:-1);
}

void solve(){
    cin>>n>>m;
    fr(i,0,m){
    	int a,b,c,f; cin>>a>>b>>c>>f;
    	arr.push_back((edge){--a,--b,c,f});
    	arr.push_back((edge){b,a,c,f});
    	flows.push_back(f);
    }
    double ans=0;
    for(int&fl:flows){
    	int cost=bellman(fl);
    	if(cost==-1) continue;
    	ans=max(ans,(fl*1.0)/cost);
    }
    cout<<(int)(ans*1e6)<<nL;
}

int main(){
	freopen("pump.in","r",stdin);
	freopen("pump.out","w",stdout);
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}