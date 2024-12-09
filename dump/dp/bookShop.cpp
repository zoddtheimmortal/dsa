/** 
 immortalzodd
 13.07.2024 09:22:22
 bookShop
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

ll n,x;
vi page,price;

void solve(){
    cin>>n>>x;
    price.assign(n,0); for(int&x:price) cin>>x;
    page.assign(n,0); for(int&x:page) cin>>x;

    vector<vi> dp(n+1,vi(x+1,0));
    fr(i,1,n+1){
    	fr(j,1,x+1){
    		int c=price[i-1],p=page[i-1];
    		dp[i][j]=dp[i-1][j];
    		if(j-c>=0) dp[i][j]=max(dp[i][j],p+dp[i-1][j-c]);
    	}
    }
    cout<<dp[n][x]<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}