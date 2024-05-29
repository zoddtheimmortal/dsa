/** 
 immortalzodd
 22.05.2024 20:52:46
 houseRobber
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

int rob(vector<int>&nums){
	int n=nums.size();
	vi dp(n,0);
	dp[0]=nums[0];
	fr(i,1,n){
		dp[i]=nums[i];
		fr(j,0,i-1){
			dp[i]=max(dp[i],nums[i]+dp[j]);
		}
	}
	int ans=0;
	for(int&x:dp) ans=max(ans,x);
	return ans;
}

void solve(){
    ll n; cin>>n;
    vi nums(n,0); for(int&x:nums) cin>>x;
    cout<<rob(nums)<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}