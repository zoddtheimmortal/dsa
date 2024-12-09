/** 
 immortalzodd
 18.07.2024 15:12:04
 rangeUpdateQueries
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
vl arr,tree;

void upd(ll k,ll x){
	k+=n;
	tree[k]+=x;
	for(;k>1;k/=2){
		tree[k/2]=tree[k]+tree[k^1];
	}
}

ll rangesum(ll a,ll b){
	ll sum=0;
	for(a+=n,b+=n+1;a<b;a/=2,b/=2){
		if(a%2==1) sum+=tree[a++];
		if(b%2==1) sum+=tree[--b];
	}
	return sum;
}

void solve(){
    cin>>n>>q;
    arr.assign(n+1,0); tree.assign(2*n+2,0);
    fr(i,1,n+1){
    	cin>>arr[i];
    	upd(i,arr[i]-arr[i-1]);
    }

    while(q--){
    	ll t; cin>>t;
    	if(t==1){
    		ll a,b,x; cin>>a>>b>>x;
    		upd(a,x);
    		upd(b+1,-x);
    	}else{
    		ll k; cin>>k;
    		cout<<rangesum(1,k)<<nL;
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