/** 
 immortalZodd
 02.02.2024 13:59:38
 searchingForSoulmates
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

ll operation(ll a,ll b){
	if(a==b) return 0;
	if(a>b){
		ll odd=a%2;
		return 1+odd+operation((a+odd)/2,b);
	}
	else{
		ll odd=b%2;
		return min(b-a,(1+odd+operation(a,b/2)));
	}
}

void solve(){
    ll a,b; cin>>a>>b;
    cout<<operation(a,b)<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}