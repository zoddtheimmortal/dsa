/**
 immortalZodd
 16.01.2024 20:24:24
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

bool check(vl city,vl tow,ll n,ll m,ll mid){
	ll i=0,j=0;

	while(i<n && j<m){
		if(abs(tow[j]-city[i])<=mid) i++;
		else j++;
	}
	if(i==n) return true;
	return false;
}

void solve(){
    ll n,m; cin>>n>>m;
    vl city(n); for(auto &x:city) cin>>x;
    vl tow(m); for(auto &x:tow) cin>>x;

    ll si=0,ei=abs(city[n-1]-tow[0]),ans=-1;
    while(si<=ei){
    	ll mid=si+(ei-si)/2;
    	if(check(city,tow,n,m,mid)){
    		ei=mid-1;
    		ans=mid;
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