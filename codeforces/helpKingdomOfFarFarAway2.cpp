/** 
 immortalzodd
 02.06.2024 10:34:57
 helpKingdomOfFarFarAway2
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
    bool brackets=(s[0]=='-');
    string dec="",fract="";
    int si=(brackets?1:0),n=s.size();
    while(s[si]!='.'&&si<n) dec+=s[si++];
    while(si<n) fract+=s[++si];

    string commas="";
    si=dec.size()-1;
    while(si>=0){
    	if((dec.size()-si)%3==1) commas+=',';
    	commas+=dec[si--];
    }
    if(commas[0]==',') commas.erase(0,1);
    reverse(all(commas));
    string dfract="00";
    if(fract.size()>1) dfract[0]=fract[0];
    if(fract.size()>2) dfract[1]=fract[1];
    string ans="$"+commas+"."+dfract;
    if(brackets) ans="("+ans+")";
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