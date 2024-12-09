/** 
 immortalzodd
 23.07.2024 13:31:38
 timeIsMooney
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

const int MXD=1000;
ll n,m,c;
vector<vi> arr;
vi earn;

void solve(){
    cin>>n>>m>>c;
    arr.resize(n); earn.assign(n,0);
    for(int&x:earn) cin>>x;

    fr(i,0,m){
    	ll f,s; cin>>f>>s;
    	arr[--s].push_back(--f);
    }

    vector<vi> dp(MXD+1,vi(n,-1));
    dp[0][0]=0;

    ll ans=0;
    fr(i,1,MXD+1){
    	fr(v,0,n){
    		for(int&u:arr[v]){
    			if(dp[i-1][u]!=-1){
    				dp[i][v]=max<ll>(dp[i][v],earn[v]+dp[i-1][u]);
    			}
    		}
    	}
    	ans=max<ll>(ans,dp[i][0]-c*i*i);
    }
    cout<<ans<<nL;
}

int main(){
    fast_io;
    ll t=1;
    freopen("time.in","r",stdin);
    freopen("time.out","w",stdout);
    // cin>>t;

    while(t--){
        solve();
    }
}