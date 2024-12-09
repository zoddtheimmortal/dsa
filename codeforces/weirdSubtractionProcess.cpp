/** 
 immortalzodd
 01.06.2024 00:44:00
 weirdSubtractionProcess
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

ll a,b;

ll multiplier(ll a,ll b){
	ll si=0,ei=(b/a+1);
	ll ans=0;
	while(si<=ei){
		ll mid=si+(ei-si)/2;
		if(b-mid*a>=0){
			ans=mid;
			si=mid+1;
		}
		else ei=mid-1;
	}
	return ans;
}

void solve(){
	cin>>a>>b;
	while(a>0&&b>0){
		if(a>=2*b) a-=multiplier(2*b,a)*2*b;
		else if(b>=2*a) b-=multiplier(2*a,b)*2*a;
		else break;
	}
	cout<<a<<" "<<b<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}