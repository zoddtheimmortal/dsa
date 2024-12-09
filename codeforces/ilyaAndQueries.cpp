/** 
 immortalzodd
 26.06.2024 10:30:43
 ilyaAndQueries
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

string s;
ll q;

void solve(){
	cin>>s>>q;
	int n=s.size();
	vi dp(n+1,0);

	fr(i,2,n+1){
		dp[i]=dp[i-1]+(s[i-1]==s[i-2]);
	}
	while(q--){
		int l,r; cin>>l>>r;
		cout<<dp[r]-dp[l]<<nL;
	}

}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}