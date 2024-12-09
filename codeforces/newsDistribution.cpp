/** 
 immortalzodd
 15.07.2024 10:05:00
 newsDistribution
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

ll n,m;
vi parent,sz;

int find(int x){
	while(x!=parent[x]) x=parent[x];
	return x;
}

bool unite(int x,int y){
	x=find(x); y=find(y);
	if(x==y) return false;
	if(sz[x]<sz[y]) swap(x,y);
	sz[x]+=sz[y];
	parent[y]=x;
	return true;
}

void solve(){
    cin>>n>>m;
    parent.assign(n,0); sz.assign(n,1);
    fr(i,0,n) parent[i]=i;

    fr(i,0,m){
    	ll s; cin>>s;
    	vi grp(s,0);
    	for(int&x:grp) cin>>x;
    	if(s==0||s==1) continue;
    	fr(i,1,s){
    		unite(grp[i]-1,grp[i-1]-1);
    	}
    }

    fr(i,0,n){
    	cout<<sz[find(i)]<<" ";
    }
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