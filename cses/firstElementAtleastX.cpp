/** 
 immortalzodd
 26.07.2024 10:55:17
 firstElementAtleastX
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

const int MXN=1e5+5;
int arr[MXN],segtree[4*MXN];
int n,q;

void build(int l=1,int r=n,int v=1){
	if(l==r) segtree[v]=arr[l];
	else{
		int mid=l+(r-l)/2;
		build(l,mid,2*v);
		build(mid+1,r,2*v+1);
		segtree[v]=max(segtree[2*v],segtree[2*v+1]);
	}
}

void update(int x,int v){
	v+=n;
	segtree[v]=x;
	for(;v>1;v/=2){
		segtree[v/2]=max(segtree[v],segtree[v^1]);
	}
}

int query(int val, int l=1,int r=n,int v=1){
	if(segtree[v]<=val) return -1;
	if(l==r) return l;
	else{
		int mid=l+(r-l)/2;
		int res=query(val,l,mid,2*v);
		if(res==-1) res=query(val,mid+1,r,2*v+1);
		return res;
	}
}

void solve(){
    cin>>n>>q;
    fr(i,1,n+1) cin>>arr[i];
    build();

    fr(i,0,q){
    	int t,x; cin>>t>>x;
    	if(t==1){
    		int val; cin>>val;
    		update(val,x);
    	}
    	else{
    		cout<<query(x)<<nL;
    	}
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