/**
 immortalZodd
 24.01.2024 23:03:20
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

bool check(vl city,vl tow,ll n,ll m,ll r){
	ll ci=0,ti=0;
	/* 2p approach to see if there exists atleast 1 tower<=r distance */
	while(ci<n && ti<m){
		ll dist=abs(city[ci]-tow[ti]);
		if(dist<=r) ci++;
		if(dist>r) ti++;
		if(ci==n) return true;
	}
	return false;
}

void solve(){
    ll n,m; cin>>n>>m;
    vl city(n,0),tow(m,0);
    for(auto& x:city) cin>>x;
    for(auto& x:tow) cin>>x;

    ll si=0,ei=max(abs(city[n-1]-tow[0]),abs(city[0]-tow[m-1]));
	ll r=0;

	/* binary search b/w 0 and max distance to find min r */
	
	while(si<=ei){
		ll mid=si+(ei-si)/2;
		if(check(city,tow,n,m,mid)){
			r=mid;
			ei=mid-1;
		}
		else si=mid+1;
	}

	cout<<r<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}