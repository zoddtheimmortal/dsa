/**
 immortalZodd
 20.01.2024 00:10:54
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
	freopen("div7.in","r",stdin);
	freopen("div7.out","w",stdout);
    ll n; cin>>n;
    ll psum=0,ans=0,mod=0;
    vi rem(n,-1);
    fr(i,0,n){
    	int cow; cin>>cow;
    	psum+=cow;
    	mod=psum%7;
    	if(rem[mod]==-1){
    		rem[mod]=i;
    	}
    	else{
    		ans=max(ans,i-rem[mod]);
    	}
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