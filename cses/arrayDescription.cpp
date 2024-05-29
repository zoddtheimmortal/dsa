/** 
 immortalzodd
 21.05.2024 20:36:31
 arrayDescription
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

ll n,m;
vi arr;

void solve(){
	unsigned int MOD=1e9+7;
    cin>>n>>m;
    arr.resize(n); for(int&x:arr) cin>>x;
    vector<vi> dp(n,vi(m+1,0));
    fr(i,0,m+1) dp[0][i]=(arr[0]==0||arr[0]==i?1:0);

    fr(i,1,n){
    	if(arr[i]==0){
    		fr(j,1,m+1){
    			for(int k:{-1,0,1}){
    				if(j+k>=1&&j+k<=m){
    					(dp[i][j]+=dp[i-1][j+k])%=MOD;
    				}
    			}
    		}
    	}else{
    		for(int k:{-1,0,1}){
    			if(arr[i]+k>=1&&arr[i]+k<=m){
    				(dp[i][arr[i]]+=dp[i-1][arr[i]+k])%=MOD;
    			}
    		}
    	}
    }
    int ans=0;
    fr(i,1,m+1){
    	(ans+=dp[n-1][i])%=MOD;
    }
    cout<<ans<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}