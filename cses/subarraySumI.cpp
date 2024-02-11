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
    ll n,q; cin>>n>>q;
    vl arr(n,0); for(auto &x:arr) cin>>x;
    ll si=0,ei=0,ans=0,cur=0;
    while(si<n){
    	while(ei<n){
    		cur+=arr[ei++];
    		if(cur>q){
    			ei--;
    			cur-=arr[ei];
    			break;
    		}
    	}
    	if(cur==q) ans++;
    	cur-=arr[si++];
    }
    if(cur==q) ans++;
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