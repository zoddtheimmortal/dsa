/** 
 immortalzodd
 03.08.2024 21:04:42
 scale
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
    ll n,k; cin>>n>>k;
    vector<string> arr(n); for(string&s:arr) cin>>s;

    for(int i=0;i<n;i+=k){
    	for(int j=0;j<n;j+=k) cout<<arr[i][j];
    	cout<<nL;
    }
}

int main(){
    fast_io;
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}