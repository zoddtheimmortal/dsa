/** 
 immortalzodd
 19.03.2024 23:49:24
 quests
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
    ll n,k; cin>>n>>k;
    vi a(n,0),b(n,0);
    for(auto&x:a) cin>>x;
    for(auto&x:b) cin>>x;

    vi a_sum(n+1,0);
	fr(i,0,n) a_sum[i+1]=a[i]+a_sum[i];

	ll ans=0,mx=0;
	fr(i,0,min(n,k)){
		mx=max<ll>(b[i],mx);
		ll temp=a_sum[i+1]-a_sum[0]+((k-i-1)*mx);
		ans=max(temp,ans);
	}
	cout<<ans<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}