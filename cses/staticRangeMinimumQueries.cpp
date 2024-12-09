/** 
 immortalzodd
 18.07.2024 13:11:21
 dynamicRangeMinimumQueries
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

ll n,q;
vl tree;

void add(ll k,ll x){
	k+=n;
	tree[k]=x;
	for(;k>1;k/=2){
		tree[k/2]=min(tree[k],tree[k^1]);
	}
}

ll rangemin(ll x,ll y){
	ll rmin=INT64_MAX;
	for(x+=n,y+=n;x<y;x/=2,y/=2){
		if(x%2==1) rmin=min(rmin,tree[x++]);
		if(y%2==1) rmin=min(rmin,tree[--y]);
	}
	return rmin;
}

void solve(){
	cin>>n>>q;
	tree.assign(2*n,0);
	fr(i,0,n){
		ll x; cin>>x;
		add(i,x);
	}

	while(q--){
		ll x,y; cin>>x>>y;
		cout<<rangemin(x-1,y)<<nL;
	}
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}