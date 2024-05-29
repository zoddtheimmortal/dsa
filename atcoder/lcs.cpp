/** 
 immortalzodd
 26.05.2024 10:57:38
 lcs
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

void solve(){
    string a,b; cin>>a>>b;
    int n=a.size(),m=b.size();
    vector<vi> dp(n+1,vi(m+1,0));
    vector<vector<char>> rec(n+1,vector<char>(m+1));
    fr(i,1,n+1){
    	fr(j,1,m+1){
    		if(a[i-1]==b[j-1]){
    			dp[i][j]=1+dp[i-1][j-1];
    			rec[i][j]='a';
    		}
    		else{
    			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    			rec[i][j]=(dp[i][j]==dp[i-1][j]?'l':'u');
    		}
    	}
    }
    string lcs="";
    int i=n,j=m;
    while(i>0&&j>0){
    	if(rec[i][j]=='a'){
    		lcs+=a[i-1];
    		i--; j--;
    	}
    	if(rec[i][j]=='l') i--;
    	if(rec[i][j]=='u') j--;
    }
    reverse(all(lcs));
    cout<<lcs<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}