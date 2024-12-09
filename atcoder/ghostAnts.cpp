/** 
 immortalzodd
 17.07.2024 11:28:31
 ghostAnts
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

ll n,t;
vi fwd,bwd;
string s;

void solve(){
    cin>>n>>t;
    cin>>s;
    fr(i,0,n){
    	int x; cin>>x;
    	if(s[i]=='1'){
    		fwd.push_back(x);
    	}else bwd.push_back(x);
    }

    sort(all(fwd)); sort(all(bwd));
    ll ans=0;
    int si=0,ei=0,n=fwd.size(),m=bwd.size();
    while(si<n&&ei<m){
    	if(bwd[ei]-fwd[si]<=2*t){
    		ei++;
    	}else{
    		ans+=(ei+1);
    		ei++;
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