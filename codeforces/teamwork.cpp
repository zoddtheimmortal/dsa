/** 
 immortalzodd
 23.07.2024 22:38:15
 teamwork
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

ll n,k;
vi arr;
const int MXN=1e4+5;
ll dp[MXN]={0};

ll getmax(int si,int ei){
	ll ans=INT64_MIN;
	fr(i,si,ei+1) ans=max<ll>(ans,arr[i]);
	return ans;
}

void solve(){
    cin>>n>>k;
    arr.resize(n); for(int&x:arr) cin>>x;

    fr(i,1,n+1){
    	fr(j,1,k+1){
    		if(i-j>=0) dp[i]=max(dp[i],dp[i-j]+getmax(i-j,i-1)*j);
    	}
    }
    cout<<dp[n]<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}