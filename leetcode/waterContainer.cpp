/**
 immortalZodd
 20.01.2024 00:40:43
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
    ll si=0,ei=n-1,area=0;
    while(si<=ei){
    	ll width=ei-si;
    	area=max(area,min(arr[si],arr[ei])*width);
    	if(arr[si]>arr[ei]) ei--;
    	else si++;
    }

    cout<<area<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}