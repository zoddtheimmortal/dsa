/** 
 immortalzodd
 22.05.2024 17:57:40
 moneySums
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

ll n;
vi coins;

void solve(){
    cin>>n;
    coins.assign(n,0);
    int x=0;
    for(int&c:coins){
    	cin>>c;
    	x+=c;
    }
    vector<vi> dp(x+1,vi(n,0));
    fr(i,0,n) dp[0][i]=1;
    fr(i,1,x+1) dp[i][0]=(coins[0]==i);

    vi sums;
    fr(i,1,x+1){
    	bool possible=false;
    	fr(j,0,n){
    		if(j-1>=0) dp[i][j]|=dp[i][j-1];
    		if(j-1>=0&&i-coins[j]>=0) dp[i][j]|=dp[i-coins[j]][j-1];
    		possible=(dp[i][j]==1);
    	}
    	if(possible) sums.push_back(i);
    }
    cout<<sums.size()<<nL;
    for(int&x:sums) cout<<x<<" ";
    cout<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}