/** 
 immortalzodd
 23.06.2024 18:09:59
 longestPalindromicSubstring
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

string middleOut(int i,int j,string s){
	int n=s.size();
	string ans="";
	while(i>=0&&j<n&&s[i]==s[j]){
		ans=s.substr(i,j-i+1);
		cout<<i<<" "<<j<<" "<<ans<<nL;
		i--;
		j++;
	}
	return ans;
}

string longestPalindrome(string s) {
	int n=s.size();
	string ans="";
	for(int i=0;i<n;i++){
		string a=middleOut(i,i,s);
		string b=middleOut(i,i+1,s);

		if(a.size()<b.size()) swap(a,b);
		if(a.size()>ans.size()) ans=a;
	} 
	return ans;
}

void solve(){
	string s; cin>>s;
	cout<<longestPalindrome(s)<<nL;
}

int main(){
	fast_io;
	ll t=1;
    // cin>>t;

	while(t--){
		solve();
	}
}