/** 
 immortalzodd
 11.07.2024 22:21:12
 grouping
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
vl dp;

const ll BIG=-1e18;

ll group(ll mask){
	if(dp[mask]!=BIG) return dp[mask];

	ll ans=0;
	for(ll i=0;i<n;i++){
		for(ll j=i+1;j<n;j++){
			if((mask&(1<<i))&&(mask&(1<<j))){
				ans+=arr[i][j];
			}
		}
	}

	for(ll i=mask&(mask-1);i>0;i=(i-1)&mask){
		ans=max(ans,group(i)+group(mask^i));
	}
	return dp[mask]=ans;
}

void solve(){
    cin>>n;
    arr.assign(n,vi(n,0));
    fr(i,0,n){
    	fr(j,0,n) cin>>arr[i][j];
    }
    dp.assign((1<<n),BIG);
    cout<<group((1<<n)-1)<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}