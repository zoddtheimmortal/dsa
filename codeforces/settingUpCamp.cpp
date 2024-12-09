/** 
 immortalzodd
 07.08.2024 22:44:57
 settingUpCamp
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
    ll a,b,c; cin>>a>>b>>c;
    ll ans=a;

    ans+=b/3;
    b%=3;
    if((b==1&&c<2)||(b==2&&c<1)){
    	cout<<-1<<nL;
    	return;
    }
    if(b==2){
    	b++; c--;
    }
    if(b==1){
    	b+=2; c-=2;
    }
    ans+=b/3;

    ans+=(c/3);
    c%=3;
    ans+=(c/2);
    c%=2;
    ans+=c;

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