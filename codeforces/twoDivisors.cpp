/** 
 immortalzodd
 18.03.2024 19:20:49
 twoDivisors
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

ll gcd(ll a,ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}

void solve(){
    ll a,b; cin>>a>>b;
    if(a==1) cout<<b*b<<nL;
    else if(b%a==0) cout<<(b*b)/a<<nL;
    else cout<<(a*b)/gcd(a,b)<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}