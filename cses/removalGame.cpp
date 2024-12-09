/** 
 immortalzodd
 31.05.2024 17:48:26
 removalGame
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

ll n;
vi arr;

void solve(){
	cin>>n;
	arr.assign(n,0); for(int&x:arr) cin>>x;
	vector<vl> dp(n,vl(n,0LL));
	rf(i,0,n-1){
		fr(j,i,n){
			if(i==j){
				dp[i][j]=arr[i];
				continue;
			}
			dp[i][j]=max(arr[j]-dp[i][j-1],arr[i]-dp[i+1][j]);
		}
	}
	ll sum=0;
	for(int&x:arr) sum+=x;
	cout<<(sum+dp[0][n-1])/2<<nL;
	/* how tf did u get this? F+S=sum, F-S=dp[0][n-1]->solve this */
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}