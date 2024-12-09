/** 
 immortalzodd
 20.06.2024 22:18:57
 longestIncreasingPathInAMatrix
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

    int longestIncreasingPath(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vi> dp1(n, vi(m, 1)), dp2(n, vi(m, 1));

        for (int i = 1; i < n; i++)
            if (grid[i][0] > grid[i - 1][0])
                dp1[i][0] = 1 + dp1[i - 1][0];
        for (int j = 1; j < m; j++)
            if (grid[0][j] > grid[0][j - 1])
                dp1[0][j] = 1 + dp1[0][j - 1];

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(grid[i][j]>grid[i][j-1]){
                    dp1[i][j]=max(dp1[i][j],1+dp1[i][j-1]);
                }
                if(grid[i][j]>grid[i-1][j]){
                    dp1[i][j]=max(dp1[i][j],1+dp1[i-1][j]);
                }
            }
        }

        for (int i = n-2; i >= 0; i--)
            if (grid[i+1][0] < grid[i][0])
                dp2[i][0] = 1 + dp2[i+1][0];
        for (int j = m-2; j >= 0; j--)
            if (grid[0][j+1] < grid[0][j])
                dp2[0][j] = 1 + dp2[0][j+1];

        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
                if(grid[i][j+1]<grid[i][j]){
                    dp2[i][j]=max(dp2[i][j],1+max(dp2[i][j+1]);
                }
                if(grid[i+1][j]<grid[i][j]){
                    dp2[i][j]=max(dp2[i][j],1+max(dp2[i+1][j],dp1[i][j+1]));
                }
            }
        }

        fr(i,0,n){
        	fr(j,0,m) cout<<dp1[i][j]<<" ";
        	cout<<nL;
        }

        fr(i,0,n){
        	fr(j,0,m) cout<<dp2[i][j]<<" ";
        	cout<<nL;
        }

        int ans=0,a,b;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
            	ans=max(ans,max(dp2[i][j],dp1[i][j]));
            }
        }
        return ans;
    }

void solve(){
    ll n,m; cin>>n>>m;
    vector<vi> arr(n,vi(m));
    fr(i,0,n){
    	fr(j,0,m) cin>>arr[i][j];
    }
    cout<<longestIncreasingPath(arr)<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}