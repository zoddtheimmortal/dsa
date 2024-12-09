/** 
 immortalzodd
 14.07.2024 17:46:27
 palindromeTree
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

ll n,m,q;
vector<vi> arr;
vector<char> alps;
string s="";

void dfs(int x,int p){
	for(int&y:arr[x]){
		if(y!=p) dfs(y,x);
	}
	s+=alps[x];
}

bool checkPalindrome(string a){
	int si=0,ei=a.size()-1;
	while(si<ei){
		if(s[si]!=s[ei]) return false;
		si++; ei--;
	}
	return true;
}

void solve(){
    cin>>n>>m>>q;
    arr.resize(n);
    fr(i,0,m){
    	ll f,s; cin>>f>>s;
    	arr[--f].push_back(--s);
    	arr[s].push_back(f);
    }
    alps.resize(n); for(char&c:alps) cin>>c;

    while(q--){
    	int x; cin>>x;
    	s="";
    	dfs(x-1,x-1);
    	cout<<s<<nL;
    	cout<<checkPalindrome(s)<<nL;
    }
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}