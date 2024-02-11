/**
 immortalZodd
 16.01.2024 20:02:10
**/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

#define pb push_back
#define v(x) vector<x>
#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define rep(i,arr) for(auto i:arr)
#define nL "\n"

bool check(vl arr,ll n,ll mid,ll k){
	ll m=0;
	for(int i=0;i<n;i++){
		m+=(mid/arr[i]);
		if(m>=k) return true;
	}
	return false;
}

void solve(){
    ll n,k; cin>>n>>k;
    vl arr(n); for(auto &x:arr) cin>>x;
    sort(all(arr));

    ll si=0,ei=(arr[n-1]*k),ans=-1;
    while(si<=ei){
    	ll mid=si+(ei-si)/2;
    	if(check(arr,n,mid,k)){
    		ans=mid;
    		ei=mid-1;
    	}
    	else si=mid+1;
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