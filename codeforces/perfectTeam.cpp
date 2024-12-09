/** 
 immortalzodd
 24.06.2024 20:32:20
 perfectTeam
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

ll c,m,x;

bool check(ll n){
	ll dc=c-n,dn=m-n,dx=x+dc+dn;
	return(dc>=0&&dn>=0&&dx-n>=0);
}

void solve(){
	cin>>c>>m>>x;
	ll si=0,ei=(c+m+x)/3+2;
	ll ans=0;
	while(si<=ei){
		ll mid=si+(ei-si)/2;
		if(check(mid)){
			ans=mid;
			si=mid+1;
		}else ei=mid-1;
	}
	cout<<ans<<nL;
}

int main(){
    fast_io;
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}