/** 
 immortalzodd
 18.07.2024 14:54:21
 dynamicRangeSumFenwick
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
	x-=arr[k];
	arr[k]+=x;
	k++;
	while(k<=n){
		tree[k]+=x;
		k+=k&-k;
	}
}

ll sum(ll k){
	k++;
	ll sum=0;
	while(k>0){
		sum+=tree[k];
		k-=k&-k;
	}
	return sum;
}

void solve(){
    cin>>n>>q;
    arr.assign(n,0); tree.assign(n+1,0);

    fr(i,0,n){
    	ll x; cin>>x;
    	upd(i,x);
    }

    while(q--){
    	ll t,x,y; cin>>t>>x>>y;
    	if(t==1) upd(x-1,y);
    	else{
    		cout<<sum(y-1)-sum(x-2)<<nL;
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