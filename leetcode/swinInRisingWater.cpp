/** 
 immortalzodd
 18.06.2024 22:51:42
 swinInRisingWater
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

int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        int dx[]={-1,0,1,0},dy[]={0,-1,0,1};
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        dp[0][0]=grid[0][0];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int surMin=INT_MAX;
                for(int k=0;k<4;k++){
                    if(i+dx[k]<0||i+dx[k]>=n||j+dy[k]<0||j+dy[k]>=n) continue;
                    surMin=min(surMin,dp[i+dx[k]][j+dy[k]]);
                }
                cout<<i<<" "<<j<<" "<<surMin<<" "<<grid[i][j]<<nL;
                dp[i][j]=max(grid[i][j],surMin);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<nL;
        }
        return dp[n-1][n-1];
}

void solve(){
    int n; cin>>n;
    vector<vi> grid(n,vi(n,0));
    fr(i,0,n){
    	fr(j,0,n) cin>>grid[i][j];
    }
    cout<<swimInWater(grid)<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}