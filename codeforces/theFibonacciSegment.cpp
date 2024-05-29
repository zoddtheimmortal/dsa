/** 
 immortalzodd
 29.05.2024 15:21:54
 theFibonacciSegment
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
    ll n; cin>>n;
    vi arr(n,0); for(int&x:arr) cin>>x;
    int si=0,ei=2,ans=(n==2?2:1);
    while(si<n&&ei<n){
    	while(ei<n&&arr[ei]==arr[ei-1]+arr[ei-2]) ei++;
    	ans=max(ans,ei-si);
    	si=ei-1;
    	ei+=1;
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