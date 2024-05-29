/** 
 immortalzodd
 25.05.2024 22:33:17
 knapsack2
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

ll n,w;
vi wt,val;

void solve(){
	cin>>n>>w;
	wt.assign(n,0); val.assign(n,0);
	fr(i,0,n) cin>>wt[i]>>val[i];
	vl dp(w+1,0);
	fr(i,1,n+1){
		rf(j,0,w){
			if(j-wt[i-1]>=0){
				dp[j]=max<ll>(dp[j],val[i-1]+dp[j-wt[i-1]]);
			}
		}
	}
	cout<<dp[w]<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}