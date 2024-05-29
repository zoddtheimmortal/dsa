/** 
 immortalzodd
 24.05.2024 12:15:41
 phoneDesktop
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

void solve(){
    ll x,y; cin>>x>>y;
    int ans=0;
    while(y>1){
    	y-=2;
    	x-=7;
    	ans++;
    }
    if(y==1){
    	ans++;
    	y-=1;
    	x-=11;
    }
    while(x>0){
    	x-=15;
    	ans++;
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