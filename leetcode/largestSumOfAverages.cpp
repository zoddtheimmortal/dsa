/** 
 immortalzodd
 28.07.2024 13:13:38
 largestSumOfAverages
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

double largestSumOfAverages(vector<int>& arr, int K) {
        int n=arr.size();
        double dp[105][105]={0.0};
        vi pfix(n+1,0); for(int i=0;i<n;i++) pfix[i+1]=pfix[i]+arr[i];

        for(int i=1;i<n+1;i++) dp[i][0]=1.0*(pfix[i]-pfix[0])/i;

        for(int i=1;i<n+1;i++){
            for(int j=1;j<i+1;j++){
                for(int k=1;k<K+1;k++){
                    double cavg=1.0*(pfix[i]-pfix[j-1])/(i-j+1);
                    dp[i][k]=max(dp[i][k],dp[j-1][k-1]+cavg);
                }
            }
        }

        fr(k,0,K+1){
        	fr(i,0,n+1) cout<<dp[i][k]<<" ";
        	cout<<nL;
        }

        return dp[n][K];
    }

void solve(){
    int n,k; cin>>n>>k;
    vi arr(n); for(int&x:arr) cin>>x;
    cout<<largestSumOfAverages(arr,k)<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}