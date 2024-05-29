/** 
 immortalzodd
 23.05.2024 22:39:57
 fruitFeast
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

ll n,a,b;
bool dp[2][5000001];

void solve(){
	cin>>n>>a>>b;
	dp[0][0]=true;
	fr(i,0,n+1){
		if(i-a>=0) dp[0][i]|=dp[0][i-a];
		if(i-b>=0) dp[0][i]|=dp[0][i-b];
		dp[1][i/2]|=dp[0][i];
	}

	fr(i,0,n+1){
		if(i-a>=0) dp[1][i]|=dp[1][i-a];
		if(i-b>=0) dp[1][i]|=dp[1][i-b];
	}

	for(int i=n;i>=0;i--){
		if(dp[1][i]){
			cout<<i<<nL;
			break;
		}
	}
}

int main(){
	freopen("feast.in","r",stdin);
	freopen("feast.out","w",stdout);
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}