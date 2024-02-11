/** 
 immortalZodd
 26.01.2024 00:06:21
 taskAndDeadlines
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
    vector<pair<ll,ll>> arr(n,make_pair(0,0));
    fr(i,0,n){
    	cin>>arr[i].first>>arr[i].second;
    }
    sort(all(arr));
    ll r=0,time=0;
    fr(i,0,n){
    	time+=arr[i].first;
    	r+=(arr[i].second-time);
    }
    cout<<r<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}