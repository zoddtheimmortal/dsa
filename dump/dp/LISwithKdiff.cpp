/** 
 immortalzodd
 18.07.2024 10:03:49
 LISwithKdiff
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
    ll n,k; cin>>n>>k;
    vi arr(n); for(int&x:arr) cin>>x;

    map<int,int> dp;
    for(int&x:arr) dp[x]=0;

    ll len=0,li=0;
	for(int&x:arr){
		if(dp.find(x-k)!=dp.end()) dp[x]=max(dp[x],1+dp[x-k]);
		if(dp[x]>len){
			len=dp[x];
			li=x;
		}
	}

	vi ans;
	rf(i,0,n-1){
		if(arr[i]==li){
			ans.push_back(li);
			li-=k;
		}
	}
	ans.push_back(ans.size());
	reverse(all(ans));
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