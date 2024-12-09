/** 
 immortalzodd
 09.06.2024 23:16:43
 hamiltonianFlights
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

const int MAX_N=20;
const unsigned int MOD=1e9+7;

ll n,m;
vector<vi> arr;
int dp[1<<MAX_N][MAX_N];

void solve(){
    cin>>n>>m;
    arr.resize(n);
    fr(i,0,m){
    	ll f,s; cin>>f>>s;
    	arr[--s].push_back(--f);
    }

    dp[1][0]=1;
    fr(s,2,1<<n){
    	if((s&(1<<0))==0) continue;
    	if((s&(1<<(n-1)))&&(s!=((1<<n)-1))) continue;

    	fr(k,0,n){
    		if((s&(1<<k))==0) continue;
    		for(int&u:arr[k]){
    			if(s&(1<<u)){
    				dp[s][k]+=dp[s-(1<<k)][u];
    				dp[s][k]%=MOD;
    			}
    		}
    	}
    }
    cout<<dp[(1<<n)-1][n-1]<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}