/** 
 immortalZodd
 25.01.2024 15:21:39
 concertTickets
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
    ll n,m; cin>>n>>m;
    multiset<ll> ms;
    fr(i,0,n){
    	ll x; cin>>x;
    	ms.insert(x);
    }
    while(m--){
    	ll price; cin>>price;
    	auto it=ms.upper_bound(price);
    	if(it==ms.begin()){
    		cout<<-1<<nL;
    	}else{
    		cout<<*(--it)<<nL;
    		ms.erase(it);
    	}
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}