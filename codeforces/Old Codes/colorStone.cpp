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
    string str1,str2; cin>>str1>>str2;
    ll i=0,j=0,ans=0;
    for(;i<str1.size()&&j<str2.size();){
        if(str1[i]==str2[j]){
            // cout<<str1[i]<<" "<<i<<" "<<j<<nL;
            ans++; i++; j++;
        }
        else{
            j++;
        }
    }
    cout<<ans+1<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}