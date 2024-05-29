/** 
 immortalzodd
 24.05.2024 00:19:59
 increasingSubsequence
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

ll n;
vi arr;

void solve(){
	cin>>n;
	arr.assign(n,0); for(int&x:arr) cin>>x;
	vi dp;

	for(int&x:arr){
		int pos=lower_bound(all(dp),x)-dp.begin();
		if(pos==dp.size()) dp.push_back(x);
		else dp[pos]=x;
	}
	cout<<dp.size()<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}