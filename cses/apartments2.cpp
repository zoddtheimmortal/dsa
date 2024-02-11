/** 
 immortalZodd
 25.01.2024 22:19:47
 apartments2
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
    ll n,m,k; cin>>n>>m>>k;
    vl apt(n,0),ppl(m,0);
    fr(i,0,n) cin>>apt[i];
    fr(i,0,m) cin>>ppl[i];
	sort(all(apt)); sort(all(ppl));
	ll i=0,j=0,ans=0;
	while(i<n && j<m){
		if(apt[i]-k>ppl[j]) j++;
		else if(apt[i]-k<=ppl[j] && ppl[j]<=apt[i]+k){
			i++; j++;
			ans++;
		}
		else if(apt[i]+k<ppl[j]) i++;
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