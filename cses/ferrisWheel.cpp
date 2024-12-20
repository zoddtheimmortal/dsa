/**
 immortalZodd
 25.01.2024 23:43:25
 ferrisWheel
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
    ll n,k; cin>>n>>k;
    vl arr(n,0); for(auto &x:arr) cin>>x;
    sort(all(arr));

    /* always pair lightest kid with heaviest kid, if weight limit exceeds,
    	then let heavy kid be in a gondola alone */
    ll si=0,ei=n-1,ans=0;
    while(si<=ei){
    	if(arr[si]+arr[ei]>k){
    		ans++;
    		ei--;
    	}
    	else if(arr[si]+arr[ei]<=k){
    		ans++;
    		si++;
    		ei--;
    	}
    }
    cout<<ans<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}