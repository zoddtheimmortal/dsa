/** 
 immortalzodd
 26.06.2024 21:41:42
 flippingGame
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
#define F first
#define S second

using pii = pair<int,int>;

ll n;
vi arr;
ll allOnes=0;

ll flip(pii l,pii r){
	return r.F-l.F+allOnes-(r.S-l.S);
}

void solve(){
	cin>>n;
	vi arr(n,0); for(int&x:arr) cin>>x;
    vector<pii> prefix(n+1);
    prefix[0]={0,0};
    fr(i,0,n){
    	prefix[i+1]={prefix[i].F+(arr[i]==0),prefix[i].S+(arr[i]==1)};
    	allOnes+=(arr[i]==1);
    }

    ll ans=0;
    fr(i,0,n+1){
    	fr(j,i+1,n+1){
    		ll ones=flip(prefix[i],prefix[j]);
    		ans=max(ans,ones);
    	}
    }
    cout<<ans<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}