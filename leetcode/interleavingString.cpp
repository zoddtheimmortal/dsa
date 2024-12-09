/** 
 immortalzodd
 20.06.2024 20:01:21
 interleavingString
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

bool isInterleave(string s1, string s2, string s3) {
	int n = s1.size(), m = s2.size(), p=s3.size();
	if(p==0) return false;
	if(n==0||m==0) return (s1==s3||s2==s3);
	vector<vi> dp(n, vi(m, 1));
	dp[0][0] = (s1[0] == s3[0]) || (s2[0] == s3[0]);
	for (int i = 1; i < min(n,p); i++)
		dp[i][0] = (dp[i - 1][0]) && (s1[i] == s3[i]);
	for (int j = 1; j < min(m,p); j++) (dp[0][j]=dp[0][j-1])&&(s2[j]==s3[j]);
	fr(k,1,p){
		fr(i,1,n){
			fr(j,1,m){
				dp[i][j]|=(s3[k]==s1[i]&&dp[i-1][j])||(s3[k]==s2[j]&&dp[i][j-1]);
			}
		}
	}
	return (dp[n-1][m-1]);
}

void solve(){
	string a,b,c; cin>>a>>b>>c;
	a="";
	cout<<isInterleave(a,b,c)<<nL;
}

int main(){
	fast_io;
	ll t=1;
    // cin>>t;

	while(t--){
		solve();
	}
}