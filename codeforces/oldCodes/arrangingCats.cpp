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
    ll n; cin>>n;
    string s1,s2; cin>>s1>>s2;

    ll c1=0,c2=0,k=0;
    fr(i,0,n){
    	if(s1[i]==s2[i] && s1[i]=='1') k++;
    	if(s1[i]=='1') c1++;
    	if(s2[i]=='1') c2++;
    }
    ll ans=abs(c1-c2);
    ans+=(c1>c2?(c2-k):(c1-k));
    cout<<ans<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}