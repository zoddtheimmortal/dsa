/** 
 immortalzodd
 10.08.2024 23:06:07
 A
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
    ll a,b,k; cin>>a>>b>>k;
    if(k%2==1) cout<<a<<" "<<b<<nL;

    k--;

    for(int i=1;i<k+1;i+=2){
    	cout<<a-(i)<<" "<<b-(i)<<nL;
    	cout<<a+(i)<<" "<<b+(i)<<nL;    	
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