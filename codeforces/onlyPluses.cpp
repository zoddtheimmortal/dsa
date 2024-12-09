/** 
 immortalzodd
 20.07.2024 18:48:29
 onlyPluses
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
    ll a,b,c; cin>>a>>b>>c;
    priority_queue<ll,vl,greater<ll>> pq;
    pq.push(a); pq.push(b); pq.push(c);
    for(int i=0;i<5;i++){
    	ll k=pq.top();
    	pq.pop();
    	pq.push(++k);
    }

    ll ans=1;
    while(!pq.empty()){
    	ans*=pq.top();
    	pq.pop();
    }
    cout<<ans<<nL;
}

int main(){
    fast_io;
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}