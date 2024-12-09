/** 
 immortalzodd
 24.06.2024 20:23:50
 balancedTeam
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
vl arr;

void solve(){
    cin>>n;
    arr.assign(n,0); for(ll&x:arr) cin>>x;
    sort(all(arr));
    int ans=0,j=0;
    for(int i=0;i<n;i++){
    	while(j<n&&arr[j]-arr[i]<=5){
    		j++;
    		ans=max(ans,j-i);
    	}
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