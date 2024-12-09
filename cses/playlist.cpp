/** 
 immortalzodd
 15.07.2024 23:40:51
 playlist
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

ll n;
vi arr;
set<int> s;

void solve(){
    cin>>n;
    arr.resize(n); for(int&x:arr) cin>>x;
    int si=-1,ans=0;
    fr(i,0,n){
    	while(si<n-1&&!s.count(arr[si+1])) s.insert(arr[++si]);
    	ans=max<ll>(ans,si-i+1);
    	s.erase(arr[i]);
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