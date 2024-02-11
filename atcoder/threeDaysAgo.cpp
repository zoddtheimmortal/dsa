/** 
 immortalZodd
 02.02.2024 18:34:34
 threeDaysAgo
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
    string arr; cin>>arr;
    ll ans=0,n=arr.size();

    ll cur=0;
    map<int,ll> state;
    state[cur]++;

    for(auto &x:arr){
    	cur^=1<<(x-'0');
    	state[cur]++;
    }

    auto it=state.begin();
    while(it!=state.end()){
    	ll temp=it->second;
    	ans+=(temp*(temp-1))/2;
    	it++;
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