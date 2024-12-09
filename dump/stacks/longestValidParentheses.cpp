/** 
 immortalzodd
 01.07.2024 15:28:31
 longestValidParentheses
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

int longestValidParentheses(string s) {
	int n=s.size();
	stack<int> ss;
	vi dp(n+1,0);
	for(int i=1;i<n+1;i++){
		if(s[i-1]=='('){
			dp[i]++;
			ss.push(i);
		}
		else if(!ss.empty()&&s[ss.top()-1]=='('&&s[i-1]==')'){
			ss.pop();
		}
	}
	while(!ss.empty()){
		dp[ss.top()]--;
		ss.pop();
	}
	fr(i,1,n+1) dp[i]+=dp[i-1];
	for(int&x:dp) cout<<x<<" ";
	cout<<nL;
	return 2*dp[n];
}

void solve(){
	string s; cin>>s;
	cout<<longestValidParentheses(s)<<nL;
}

int main(){
	fast_io;
	ll t=1;
    // cin>>t;

	while(t--){
		solve();
	}
}