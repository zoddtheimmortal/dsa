/** 
 immortalzodd
 23.07.2024 23:15:37
 snakes
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

ll n,k;
vi arr;
vector<vl> dp;
const ll BIG=1e18;

void solve(){
    cin>>n>>k;
    arr.assign(n,0); for(int&x:arr) cin>>x;

    dp.assign(n+1,vl(k+1,0));

    ll ltnow=0;
    fr(i,1,n+1){
    	ltnow=max<ll>(ltnow,arr[i-1]);
    	dp[i][0]=i*ltnow;

    	fr(j,1,k+1){
    		dp[i][j]=BIG;
    		int netsize=arr[i-1];
    		rf(p,1,i-1){
    			dp[i][j]=min(dp[i][j],dp[p][j-1]+(i-p)*netsize);
    			netsize=max(netsize,arr[p-1]);
    		}
    	}
    }

    ll used=0;
    for(int&x:arr) used+=x;
    cout<<dp[n][k]-used<<nL;
}

int main(){
    fast_io;
    ll t=1;
    freopen("snakes.in","r",stdin);
    freopen("snakes.out","w",stdout);
    // cin>>t;

    while(t--){
        solve();
    }
}