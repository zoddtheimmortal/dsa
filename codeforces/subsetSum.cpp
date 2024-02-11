/** 
 immortalZodd
 31.01.2024 00:05:44
 subsetSum
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
    ll n,S; cin>>n>>S;
    vi arr(n,0); for(auto &x:arr) cin>>x;

    for(ll mask=0;mask<(1<<n);mask++){
    	ll sum=0;
    	for(int i=0;i<n;i++){
    		if(mask&(1<<i)) sum+=arr[i];
    	}
    	if(sum==S) cout<<"YES"<<nL;
    	else cout<<"NO"<<nL;
    }

}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}