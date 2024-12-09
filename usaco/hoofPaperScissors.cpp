/** 
 immortalzodd
 23.07.2024 14:13:37
 hoofPaperScissors
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

const int MXN=1e5+5;
int dp[MXN][21][3];
int arr[MXN];
int n,p;

void solve(){
    cin>>n>>p;
    fr(i,0,n){
        char c; cin>>c;
        if(c=='H') arr[i]=0;
        if(c=='P') arr[i]=1;
        if(c=='S') arr[i]=2;
    }

    memset(dp,0,sizeof(dp));

    fr(i,0,n){
    	fr(j,0,p+1){
            fr(k,0,3){
                if(k==arr[i]) dp[i][j][k]++;
                dp[i+1][j+1][0]=max(dp[i+1][j+1][0],dp[i][j][k]);
                dp[i+1][j+1][1]=max(dp[i+1][j+1][1],dp[i][j][k]);
                dp[i+1][j+1][2]=max(dp[i+1][j+1][2],dp[i][j][k]);

                dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]);
            }
    	}
    }
    int ans=0;
    for(int i=0;i<3;i++) ans=max(ans,dp[n-1][p][i]);
    cout<<ans<<nL;
}

int main(){
    fast_io;
    ll t=1;
    freopen("hps.in","r",stdin);
    freopen("hps.out","w",stdout);
    // cin>>t;

    while(t--){
        solve();
    }
}