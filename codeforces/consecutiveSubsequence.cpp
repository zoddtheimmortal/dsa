/** 
 immortalzodd
 18.07.2024 09:59:51
 consecutiveSubsequence
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

void solve(){
    ll n; cin>>n;
    vi arr(n); for(int&x:arr) cin>>x;
    map<int,int> dp;
    for(int&x:arr) dp[x]=0;

    ll len=0,le=0;
	for(int&x:arr){
		dp[x]=max(dp[x],1+dp[x-1]);
		if(dp[x]>len){
			len=dp[x];
			le=x;
		}
	}

	vi ans;
	rf(i,0,n-1){
		if(arr[i]==le){
			ans.push_back(i+1);
			--le;
		}
	}
	reverse(all(ans));

	cout<<ans.size()<<nL;
	for(int&x:ans) cout<<x<<" ";
	cout<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}