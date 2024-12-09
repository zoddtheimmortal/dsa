/** 
 immortalzodd
 31.05.2024 22:36:35
 theValuesYouCanMake
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

#define N 501

ll n,k;
vi arr;
bool dp[N][N][N];

void solve(){
    cin>>n>>k;
    arr.assign(n,0); for(int&x:arr) cin>>x;
    dp[0][0][0]=true;
    fr(i,1,n+1){
    	fr(j,0,k+1){
    		fr(p,0,j+1){
    			dp[i][j][p]|=dp[i-1][j][p];
    			if(j-arr[i]>=0){
    				dp[i][j][p]|=dp[i-1][j-arr[i]][p];
    				if(p-arr[i]>=0) 
    					dp[i][j][p]|=dp[i-1][j-arr[i]][p-arr[i]];
    			}
    		}
    	}
    }
    vi possible;
    fr(j,0,k+1){
    }
    cout<<possible.size()<<nL;
    for(int&x:possible) cout<<x<<" ";
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