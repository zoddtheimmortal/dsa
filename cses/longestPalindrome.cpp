/** 
 immortalzodd
 27.06.2024 18:19:54
 longestPalindrome
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

string s;
int n;

string middleOut(int i,int j){
	string ans="";
	while(i>=0&&j<n&&s[i]==s[j]){
		ans=s.substr(i,j-i+1);
		i--;
		j++;
	}
	return ans;
}

void solve(){
    cin>>s;
    n=s.size();

    string ans="";
    fr(i,0,n){
    	string a=middleOut(i,i);
    	string b=middleOut(i,i+1);
    	if(a.size()<b.size()) swap(a,b);
    	if(a.size()>ans.size()) ans=a;
    }
    cout<<ans<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}