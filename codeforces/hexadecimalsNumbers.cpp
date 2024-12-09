/** 
 immortalzodd
 06.06.2024 17:23:02
 hexadecimalsNumbers
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

int n;

void solve(){
    cin>>n;
    ll ans=0;
    fr(mask,1,(1<<30)){
    	string s="";
    	fr(i,0,30){
    		if(mask&(1<<i)) s+='1';
    		else s+='0';
    	}
    	reverse(all(s));
    	if(stoi(s)<=n) ans++;
    	else break;
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