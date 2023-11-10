#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<ld>;

#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define rep(i,arr) for(auto i:arr)
#define nL "\n"

void backtrack(string curStr,int n,int lc,int rc,vector<string> &ans);

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n; cin>>n;
	vector<string> ans;
	backtrack("",n,0,0,ans);
	rep(s,ans){
		cout<<s<<nL;
	}
}

void backtrack(string curStr,int n,int lc,int rc,vector<string> &ans){
	if(curStr.size()==(2*n)){
		ans.pb(curStr);
		return;
	}
	if(lc<n){
		curStr+='(';
		backtrack(curStr,n,lc+1,rc,ans);
		curStr.pop_back();
	}
	if(lc>rc){
		curStr+=')';
		backtrack(curStr,n,lc,rc+1,ans);
		curStr.pop_back();
	}
}