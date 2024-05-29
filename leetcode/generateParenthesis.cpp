/** 
 immortalzodd
 08.04.2024 14:11:38
 generateParenthesis
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

bool validParenthesis(string str){
	stack<char> ss;
	for(char &x:str){
		if(x=='(') ss.push(x);
		else{
			if(!ss.empty()) ss.pop();
			else return false;
		};
	}
	return ss.empty();
}

void solve(){
    ll n; cin>>n;
    n*=2;
    vector<string> ans;
    for(int mask=0;mask<(1<<n);mask++){
    	string k="";
    	for(int i=0;i<n;i++){
    		if(mask&(1<<i)) k+="(";
    		else k+=")";
    	}
    	if(validParenthesis(k)) ans.push_back(k);
    }

    for(auto&x:ans) cout<<x<<nL;
}	

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}