/**
 immortalZodd
 23.01.2024 23:33:15
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
    ll n,t; cin>>n>>t;
    vi arr(n,0); for(auto &x:arr) cin>>x;
    int si=0,ei=0,ans=0,sum=0;
    while(si<n && ei<n){
    	while(ei<n){
    		sum+=arr[ei];
    		ei++;
    		if(sum>t){
    			sum-=arr[--ei];
    			break;
    		}
    	}
    	ans=max(ans,ei-si);
    	sum-=arr[si++];
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