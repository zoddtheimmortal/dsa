/** 
 immortalZodd
 18.02.2024 22:55:51
 makeEqualAgain
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
    ll n; cin>>n;
    vi arr(n,0); for(auto &x:arr) cin>>x;
    ll prefix=0,suffix=0,i=0;
    while(i<n && arr[i]==arr[0]){
    	prefix++;
    	i++;
    }
    i=n-1;
    while(i>=0 && arr[i]==arr[n-1]){
    	i--;
    	suffix++;
    }

    if(prefix==n && suffix==n){
    	cout<<0<<nL;
    	return;
    }

    if(arr[0]==arr[n-1]){
    	cout<<n-(prefix+suffix)<<nL;
    }
    else cout<<n-max(prefix,suffix)<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}