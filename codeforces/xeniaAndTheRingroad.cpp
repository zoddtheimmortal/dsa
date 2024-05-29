/** 
 immortalzodd
 25.05.2024 18:19:52
 xeniaAndTheRingroad
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
    ll n,m; cin>>n>>m;
    vi tasks(m,0); for(int&x:tasks) cin>>x;
    ll ans=tasks[0]-1;
    fr(i,1,m){
    	ans+=(tasks[i]-tasks[i-1]>=0?(tasks[i]-tasks[i-1]):(n-tasks[i-1]+tasks[i]));
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