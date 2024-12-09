/** 
 immortalzodd
 16.07.2024 00:12:51
 elevatorRides
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

using pll = pair<ll,ll>;

ll n,x;
vi arr;

const ll BIG=1e18;

void solve(){
    cin>>n>>x;
    arr.resize(n); for(int&x:arr) cin>>x;

    vector<pll> dp(1LL<<n,{BIG,BIG});
    dp[0]={1,0};

    fr(mask,1,1<<n){
    	fr(i,0,n){
    		if(mask&(1LL<<i)){
    			auto[ppl,wt]=dp[mask^(1<<i)];
    			if(wt+arr[i]>x){
    				wt=arr[i];
    				ppl++;
    			}
    			else wt+=arr[i];
    			dp[mask]=min(dp[mask],{ppl,wt});
    		}
    	}
    }

    cout<<dp[(1<<n)-1].first<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}