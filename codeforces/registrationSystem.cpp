/** 
 immortalzodd
 24.06.2024 23:22:42
 registrationSystem
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

ll n;
map<string,int> mp;

void solve(){
    cin>>n;
    while(n--){
    	string s; cin>>s;
    	if(mp[s]==0){
    		cout<<"OK"<<nL;
    	}
    	else{
    		cout<<s<<mp[s]<<nL;
    	}
    	mp[s]++;
    }
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}