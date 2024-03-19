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

void solve(){
    string str; cin>>str;
    ll ans=0,ini=1;
    for(int i=0;i<str.size();i++){
    	if((str[i]-'0'==0 && ini!=0)||(str[i]-'0'!=0 && ini==0)){
    		ans+=abs(10-ini-(str[i]-'0'));
    	}
    	else{
    		ans+=abs(str[i]-'0'-ini);
    	}
    	ini=str[i]-'0';
    	ans++;
    }
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