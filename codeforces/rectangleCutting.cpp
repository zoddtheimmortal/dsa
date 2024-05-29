/** 
 immortalzodd
 28.03.2024 11:21:47
 rectangleCutting
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

bool checkCut(ll x,ll y){
	ll peri=x+y;
	if(x%2!=0) return false;
	x/=2,y*=2;
	if(x!=0&&peri!=x+y) return true;
	return false;
}

void solve(){
    ll x,y; cin>>x>>y;
    cout<<((checkCut(x,y)||checkCut(y,x))?"YES":"NO")<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}