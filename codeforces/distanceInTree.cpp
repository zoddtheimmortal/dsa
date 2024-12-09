/** 
 immortalzodd
 27.07.2024 10:48:26
 distanceInTree
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

const int MXN=5e4+5;
ll n,k;
ll dp[MXN][505]={0},total;
vi arr[MXN];

void dfs(int x,int p){
	dp[x][0]=1;
	for(int&y:arr[x]){
		if(y==p) continue;
		dfs(y,x);
		fr(i,0,k) total+=(dp[x][i]*dp[y][k-i-1]);
		fr(i,1,k+1) dp[x][i]+=dp[y][i-1];
	}
}

void solve(){
    cin>>n>>k;
    fr(i,0,n-1){
    	ll f,s; cin>>f>>s;
    	arr[f].push_back(s);
    	arr[s].push_back(f);
    }

    dfs(1,0);

    cout<<total<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}