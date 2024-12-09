/** 
 immortalzodd
 04.08.2024 09:02:02
 decode
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

    ll si=0,ei=0,n=s.size(),ans=0,cnt0=0,cnt1=0;
    while(ei<n){
    	cnt0+=(s[ei]=='0');
    	cnt1+=(s[ei]=='1');
    	while(si<n&&cnt0<cnt1){
    		cnt0-=(s[si]=='0');
    		cnt1-=(s[si]=='1');
    		if(cnt0==cnt1) cout<<si<<" "<<ei<<nL;
    		si++;
    	}
    	ans+=(ei-si+1);
    	ei++;
    }
    cout<<ans<<nL;
}

int main(){
    fast_io;
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}