/** 
 immortalzodd
 14.08.2024 00:23:36
 printLCS
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

    fr(i,1,n+1){
    	fr(j,1,m+1){
    		if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
    		else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
    	}
    }

    string lcs="";
    int i=n,j=m;
    while(i>0&&j>0){
    	if(a[i-1]==b[j-1]){
    		lcs.push_back(a[i-1]);
    		i--; j--;
    	}
    	else{
			if(dp[i][j-1]>dp[i-1][j]) j--;
			else i--;
    	}
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