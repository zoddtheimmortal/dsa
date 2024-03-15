/** 
 immortalZodd
 19.02.2024 15:15:35
 chayaCalender
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

ll search(ll lim,ll div){
	ll si=1,ei=lim+1,ans=0;
	while(si<=ei){
		ll mid=si+(ei-si)/2;
		if(mid*div>lim){
			ans=mid*div;
			ei=mid-1;
		}else si=mid+1;
	}
	return ans;
}

void solve(){
    int n; cin>>n;
    vi arr(n,0); for(auto &x:arr) cin>>x;

    ll ans=arr[0];
    fr(i,1,n){
    	ans=max(ans,search(ans,arr[i]));
    }
    cout<<ans<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}