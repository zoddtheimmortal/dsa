/** 
 immortalZodd
 25.01.2024 19:59:15
 studyingAlgorithms
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
    ll N,X; cin>>N>>X;
    vi arr(N,0); for(auto &x:arr) cin>>x;
    sort(all(arr));
    ll ans=0,sum=0;
    fr(i,0,N){
    	sum+=arr[i];
    	if(sum>X) break;
    	ans++;
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