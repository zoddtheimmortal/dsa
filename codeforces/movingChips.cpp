/** 
 immortalzodd
 28.03.2024 12:07:01
 movingChips
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

void solve(){
    ll n; cin>>n;
    vi arr(n,0); for(auto&x:arr) cin>>x;

    int si=0,ei=0,ans=0;
    while(si<n&&arr[si]==0) si++;
    while(si<n&&ei<n){
    	while(si<n&&arr[si]!=0) si++;
    	ei=si--;
    	while(ei<n&&arr[ei]!=1) ei++;
    	if(si<n&&ei<n) ans+=ei-si-1;
    	// cout<<si<<" "<<ei<<" "<<ans<<nL;
    	si=ei;
    }
    cout<<ans<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}