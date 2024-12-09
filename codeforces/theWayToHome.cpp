/** 
 immortalzodd
 26.06.2024 09:28:31
 theWayToHome
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

const int MAX=1e6+5;
ll n,d;
vi arr;

void solve(){
    cin>>n>>d;
    string s; cin>>s;
    vi dp(n,MAX);
    dp[0]=0;
    fr(i,1,n+1){
    	fr(j,1,d+1){
    		if(i-j>=0&&s[i-j]=='1') dp[i]=min(dp[i],1+dp[i-j]);
    	}
    }
    cout<<(dp[n-1]<MAX?dp[n-1]:-1)<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}