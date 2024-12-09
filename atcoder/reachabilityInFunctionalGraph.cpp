/** 
 immortalzodd
 16.07.2024 23:55:58
 reachabilityInFunctionalGraph
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
const ll MXN=2e5+5,MXE=1+log2(MXN);
int up[MXN][MXE];

void solve(){
    cin>>n;
    fr(i,0,n) cin>>up[i][0];

    fr(i,1,MXE){
    	fr(j,0,n) up[j][i]=up[up[j][i-1]][i-1];
    }

    ll ans=0;
    fr(i,1,n+1){
    	vi vi(n+1,0);
    	ll x=i;
    	fr(k,0,MXN){
    		fr(j,0,MXE){
    			if(!vis[x]) ans++;
    			vis[x]=1;
    			if(k&(1<<j)) 
    		}
    	}
    }
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}