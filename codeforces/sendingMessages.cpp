/** 
 immortalzodd
 21.02.2024 20:08:28
 sendingMessages
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
    ll n,f,a,b; cin>>n>>f>>a>>b;
    vi arr(n,0); for(auto &x:arr) cin>>x;

    ll hit=min(b,a*arr[0]),i=1;
    f-=hit;
    while(f>0 && i<n){
    	f-=min(b,a*(arr[i]-arr[i-1]));
    	i++;
    }

    cout<<((i==n&&f>0)?"YES":"NO")<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}