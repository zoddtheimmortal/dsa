/** 
 immortalzodd
 01.06.2024 21:37:17
 bets
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

struct ath{
	int l,r,t,c;
};

ll n,m;
vector<ath> arr;

void solve(){
    cin>>m>>n;
    arr.resize(n); for(ath&a:arr) cin>>a.l>>a.r>>a.t>>a.c;
    vi winner(n,0);
    fr(i,1,m+1){
    	int win=-1,time=INT_MAX;
    	fr(j,0,n){
    		ath a=arr[j];
    		if(a.l<=i&&i<=a.r&&a.t<time){
    			win=j; time=a.t;
    		}
    	}
    	if(win!=-1) winner[win]++;
    }
    ll ans=0;
    fr(i,0,n) ans+=winner[i]*arr[i].c;
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