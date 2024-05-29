/** 
 immortalzodd
 24.05.2024 15:47:17
 youngPhotographer
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
    int n,x; cin>>n>>x;
    vi count(1001,0);
    fr(i,0,n){
    	int x,y; cin>>x>>y;
    	fr(j,min(x,y),max(x,y)+1) count[j]++;
    }
    int ans=INT_MAX;
    fr(i,0,1001) ans=(count[i]>=n?min<ll>(ans,abs(x-i)):ans);
    cout<<(ans>=INT_MAX?-1:ans)<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}