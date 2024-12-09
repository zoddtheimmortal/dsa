/** 
 immortalzodd
 18.07.2024 13:05:51
 dynamicRangeSumQueries
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
vl arr;

void add(ll k,ll x){
	k+=n;
	arr[k]=x;
	for(;k>1;k/=2){
		arr[k/2]=arr[k]+arr[k^1];
	}
}

ll rangesum(ll x,ll y){
	ll sum=0;
	for(x+=n,y+=n;x<y;x/=2,y/=2){
		if(x%2==1) sum+=arr[x++];
		if(y%2==1) sum+=arr[--y];
	}
	return sum;
}

void solve(){
	cin>>n>>q;
	arr.assign(2*n,0);

	fr(i,0,n){
		ll x; cin>>x;
		add(i,x);
	}

	while(q--){
		ll t,x,y; cin>>t>>x>>y;
		if(t==1) add(x,y);
		else{
			// cout<<rangesum(x-1,y)<<nL;
			cout<<rangesum(x,y)<<nL;
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