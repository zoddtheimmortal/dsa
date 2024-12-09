/** 
 immortalzodd
 04.08.2024 18:52:54
 asciiCoded
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
    string s; cin>>s;
    reverse(all(s));

    int si=0,n=s.size();
    string ans="";

    while(si<n){
    	string a=s.substr(si,2);
    	string b=s.substr(si,3);

    	if((stoi(a)==32)||isalpha('\0'+stoi(a))){
    		ans+='\0'+stoi(a);
    		si+=2;
    	}
    	else if((isalpha('\0'+stoi(b)))){
    		ans+='\0'+stoi(b);
    		si+=3;
    	}
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