/** 
 immortalzodd
 02.05.2024 15:47:50
 minimizingCoins
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

ll n,sum;
vi arr;

int combos(int x){
	vi dp(x+1,INT_MAX);
	dp[0]=0;

	fr(i,1,x+1){
		for(int&c:arr){
			if(i-c>=0&&dp[i-c]!=INT_MAX){
				dp[i]=min(dp[i],1+dp[i-c]);
 			}
		}
	}
	return dp[x];
}

void solve(){
	cin>>n>>sum;
	arr.assign(n,0); for(auto&x:arr) cin>>x;

	int ans=combos(sum);
	cout<<(ans==INT_MAX?-1:ans)<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}	