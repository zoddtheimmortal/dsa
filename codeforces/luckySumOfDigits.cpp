/** 
 immortalzodd
 02.06.2024 17:56:37
 luckySumOfDigits
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
	vi dp(n+1,0),track(n+1,0);
	dp[0]=1;
	fr(i,1,n+1){
		if(i-4>=0&&dp[i-4]==1){
			dp[i]=1;
			track[i]=4;
		}
		if(i-7>=0&&dp[i-7]==1){
			dp[i]=1;
			track[i]=7;
		}
	}
	if(!dp[n]){
		cout<<-1<<nL;
		return;
	}
	string ans="";
	int i=n;
	while(i>0){
		ans+=(track[i]+'0');
		i-=track[i];
	}
	reverse(all(ans));
	cout<<ans<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}