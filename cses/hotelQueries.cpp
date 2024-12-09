/** 
 immortalzodd
 26.07.2024 10:48:39
 hotelQueries
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

const int MXN=2e5+5;

int n,q;
int segtree[4*MXN],arr[MXN];

void build(int l=1,int r=n, int v=1){
	if(l==r) segtree[v]=arr[l];
	else{
		int mid=l+(r-l)/2;
		build(l,mid,2*v);
		build(mid+1,r,2*v+1);
		segtree[v]=max(segtree[2*v],segtree[2*v+1]);
	}
}

void queryupdate(int val, int l=1,int r=n,int v=1){
	if(l==r){
		segtree[v]-=val;
		cout<<l<<" ";
	}
	else{
		int mid=l+(r-l)/2;
		if(segtree[2*v]>=val) queryupdate(val,l,mid,2*v);
		else queryupdate(val,mid+1,r,2*v+1);

		segtree[v]=max(segtree[2*v],segtree[2*v+1]);
	}
}

void solve(){
    cin>>n>>q;
    fr(i,1,n+1) cin>>arr[i];
    build();

    fr(i,0,q){
    	int x; cin>>x;
    	if(segtree[1]<x) cout<<0<<" ";
    	else queryupdate(x);
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