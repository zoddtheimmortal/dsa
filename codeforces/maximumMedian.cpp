/** 
 immortalZodd
 27.01.2024 00:12:20
 maximumMedian
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

bool check(vl arr,ll n,ll left_pts,ll target){
	ll cost=0;
	fr(i,(n+1)/2,n){
		cost+=max<ll>(0,target-arr[i]);
	}
	return cost<=left_pts;
}

void solve(){
    ll n,k; cin>>n>>k;
    vl arr(n,0); for(auto &x:arr) cin>>x;
    sort(all(arr));
    ll cur_median=arr[n/2];
    ll si=cur_median,ei=cur_median+k,ans=INT_MIN;
    while(si<=ei){
    	ll mid=si+(ei-si)/2;
    	if(check(arr,n,k-(mid-cur_median),mid)){
    		ans=mid;
    		si=mid+1;
    	}else ei=mid-1;
    }
    cout<<ans<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}