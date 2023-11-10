#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

#define pb push_back
#define v(x) vector<x>
#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define rep(i,arr) for(auto i:arr)
#define nL "\n"

struct edge{
	int s,d,w;
};

void kruskalAlgo(v(vi) arr,int n){
	ll minCost=0;

}

void solve(){
    ll n,e;
    cin>>n>>e; 
    v(struct edge) arr(e);
    fr(i,0,e){
    	ll s,d,w;
    	cin>>s>>d>>w;
    	struct edge e;
    	e.s=s;
    	e.d=d;
    	e.w=w;
    	arr.pb(e);
    }
    fr(i,0,e){
    	cout<<arr[i].s<<" "<<arr[i].d<<" "<<arr[i].w<<nL;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}