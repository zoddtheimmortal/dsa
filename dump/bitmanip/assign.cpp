/** 
 immortalzodd
 11.07.2024 21:58:03
 assign
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

ll n;
vector<vi> arr;
vi dp;

ll assign(ll mask){
	int k=__builtin_popcount(mask);
	if(k==n) return 1;
	if(dp[mask]!=-1) return dp[mask];
	ll ans=0;
	fr(i,0,n){
		if(arr[i][k]==1&&!(mask&(1LL<<i))){
			ans+=assign(mask|(1LL<<i));
		}
	}
	return dp[mask]=ans;
}

void solve(){
    cin>>n;
    arr.assign(n,vi(n,0));
    fr(i,0,n){
    	fr(j,0,n) cin>>arr[i][j];
    }
    dp.assign((1<<n),-1);
    cout<<assign(0)<<nL;
}

int main(){
    fast_io;
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}