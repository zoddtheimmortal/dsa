/** 
 immortalZodd
 19.02.2024 14:27:28
 countingDivisors
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
    int n; cin>>n;
    int count=0;
    for(int i=1;i*i<=n;i++){
    	if(n%i==0) count+=((i*i==n?1:2));
    }
    cout<<count<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}