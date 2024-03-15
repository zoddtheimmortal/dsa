/** 
 immortalzodd
 07.03.2024 09:21:03
 validParenthesis
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

void solve(){
    string s; cin>>s;
    stack<char> ss;
    for(auto&x:s){
    	if(x=='('||x=='['||x=='{') ss.push(x);
    	else{
    		if(!ss.empty()&&x==')'&&ss.top()=='(') ss.pop();
    		if(!ss.empty()&&x==']'&&ss.top()=='[') ss.pop();
    		if(!ss.empty()&&x=='}'&&ss.top()=='{') ss.pop();
    	}

    	if(ss.empty()) return fals;
    }

    cout<<(ss.empty()?"YES":"NO")<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}