/** 
 immortalZodd
 31.01.2024 11:30:52
 preparingOlympiad
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

ll n,l,r,x;

ll check(vi arr){
	ll ans=0;
	fr(mask,0,(1<<n)){
		ll tot_diff=0,min_i=-1,max_i=-1;
		if(__builtin_popcount(mask)<2) continue;
		fr(i,0,n){
			if(mask&(1<<i)){
				if(min_i==-1) min_i=i;
				max_i=i;
				tot_diff+=arr[i];
			}
		}
		if(l<=tot_diff && r>=tot_diff && x<=(arr[max_i]-arr[min_i])) ans++;
	}
	return ans;
}

void solve(){
	cin>>n>>l>>r>>x;
    vi arr(n,0); for(auto &x:arr) cin>>x;
    sort(all(arr));
    cout<<check(arr)<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}