/** 
 immortalzodd
 20.07.2024 22:48:45
 haybaleFeast
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
    ll n,m; cin>>n>>m;
    vi f(n),s(n);
    fr(i,0,n) cin>>f[i]>>s[i];

    ll si=0,ei=0,ans=INT64_MAX,fsum=0;
    multiset<ll> ms;

    while(ei<n){
    	fsum+=f[ei];
    	ms.insert(s[ei]);
    	while(si<=ei&&fsum>=m){
    		fsum-=f[si];
    		ms.erase(ms.find(s[si]));
    		ans=min(ans,*ms.rbegin());
    		si++;
    	}
    	ei++;
    }
    cout<<ans<<nL;
}

int main(){
    fast_io;
    ll t=1;
    freopen("hayfeast.in","r",stdin);
    freopen("hayfeast.out","w",stdout);
    // cin>>t;

    while(t--){
        solve();
    }
}