/** 
 immortalzodd
 26.06.2024 21:10:47
 perfectNumber
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

ll k;
const int MAX=2e7;

bool check(int x){
	ll sum=0;
	while(x){
		sum+=x%10;
		x/=10;
	}
	return (sum==10);
}

void solve(){
    cin>>k;
    ll ans=0;
    while(k){
    	ans++;
    	if(check(ans)) k--;
    }
    cout<<ans<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}