/** 
 immortalzodd
 31.05.2024 20:15:18
 candies
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
unsigned int MOD=1e9+7;

void solve(){
    cin>>n>>k;
    arr.assign(n,0); for(int&x:arr) cin>>x;
    vector<vi> dp(n+1,vi(k+1,0));
    dp[0][0]=1;
    fr(i,1,n+1){
    	fr(j,0,k+1){
    		fr(c,0,max<ll>(k-j+1,arr[i-1]+1)){
    			if(j-c>=0){
    				dp[i][j]+=dp[i-1][j-c];
    				dp[i][j]%=MOD;
    			}
    		}
    	}
    }
    fr(i,0,n+1){
        fr(j,0,k+1) cout<<dp[i][j]<<" ";
        cout<<nL;
    }
    cout<<dp[n][k]<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}