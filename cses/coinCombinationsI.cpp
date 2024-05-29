/** 
 immortalzodd
 22.04.2024 11:51:32
 coinCombinationsI
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

const unsigned int MOD=1e9+7;

void solve(){
    ll n,sum; cin>>n>>sum;
    vi coins(n,0); for(int&x:coins) cin>>x;

    vi count(sum+1,0); count[0]=1;

    fr(x,1,sum+1){
    	for(int&c:coins){
    		if(x-c>=0){
    			count[x]+=count[x-c];
    			count[x]%=MOD;
    		}
    	}
    }
    cout<<count[sum]<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}