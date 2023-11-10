#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

#define pb push_back
#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define rep(i,arr) for(auto i:arr)
#define nL "\n"

string genStr(string str){
    if(str[0]=='1') return str+"01";
    else return "01"+str;
}

void solve(){
    int n; cin>>n;
    string str; cin>>str;
    int i=0;
    while(i<n/2){
    	if(str[i]==str[n-i-1]){
    		str=str.substr(0,i)+genStr(str.substr(i,n-(2*i)))+str.substr(n-i,i);
            cout<<str<<nL;
    	}
        n=str.size();
    	i++;
    } 
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}