/** 
 immortalzodd
 31.05.2024 19:44:27
 stones
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
vi stones;

void solve(){
    cin>>n>>k;
    stones.assign(n,0); for(int&x:stones) cin>>x;
    vi dp(k+1,0);
    fr(i,1,k+1){
    	fr(j,0,n){
    		if(i-stones[j]>=0&&!dp[i-stones[j]]) dp[i]=1;
    	}
    }
    cout<<(dp[k]?"First":"Second")<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}