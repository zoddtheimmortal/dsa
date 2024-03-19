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
    ll n,k; cin>>n>>k;
    string str; cin>>str;
    unordered_map<char,int> mp;
    fr(i,0,n){
    	mp[str[i]]++;
    }
    unordered_map<char,int>::iterator it=mp.begin();
    while(it!=mp.end()){
    	cout<<it->first<<" "<<it->second<<nL;
    	it++;
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