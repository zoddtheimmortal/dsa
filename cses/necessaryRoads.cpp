/** 
 immortalzodd
 13.07.2024 09:57:51
 necessaryRoads
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

using pii = pair<int,int>;
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
    vector<pii> arr(m);
    for(pii&p:arr) cin>>p.first>>p.second;
    

    vi unn(m,0);
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}