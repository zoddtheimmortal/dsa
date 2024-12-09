/** 
 immortalzodd
 16.07.2024 22:38:16
 sum=0
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
    ll n; cin>>n;
    vi l(n),r(n);
    ll lsum=0,rsum=0;
    fr(i,0,n){
    	cin>>l[i]>>r[i];
    	lsum+=l[i]; rsum+=r[i];
    }
    if(lsum>0||rsum<0){
    	cout<<"No"<<nL;
    	return;
    }
    vi ans(n); fr(i,0,n) ans[i]=l[i];
    ll xsum=lsum;
	fr(i,0,n){
		ll d=min<ll>(r[i]-l[i],-xsum);
		ans[i]+=d;
		xsum+=d;
    }
    cout<<"Yes"<<nL;
    for(int&x:ans) cout<<x<<" ";
    cout<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}