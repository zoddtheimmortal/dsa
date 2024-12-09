/** 
 immortalzodd
 07.08.2024 22:02:32
 bigTree
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

vector<vi> arr;
int n;
string s;

void dfs(int x,int p){
	int c=s[x]-'a';
	dp[x][c]=0;
	for(int&y:arr[x]){
		if(y!=p){
			dfs(y,x);
			dp[x][c]=max(dp[x][c],1+dp[y][1-c]);
		}
	}
	ans=max(ans,dp[x][c]);
}

void solve(){
    cin>>n;
    arr.resize(n);
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}