/** 
 immortalzodd
 15.07.2024 15:40:17
 rightTriangle
**/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vl = vector<ll>;

#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define nL "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)

using pll = pair<ll,ll>;

ld dist(pll a,pll b){
	return sqrt((a.first-b.first)*(a.first-b.first)+
		(a.second-b.second)*(a.second-b.second));
}

void solve(){
    vector<pair<ll,ll>> sides(3);
    for(pair<ll,ll>&p:sides) cin>>p.first>>p.second;
    ld a=dist(sides[0],sides[1]);
	ld b=dist(sides[1],sides[2]);
	ld c=dist(sides[0],sides[2]);

	cout<<((a*a+b*b==c*c)?"Yes":"No")<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}