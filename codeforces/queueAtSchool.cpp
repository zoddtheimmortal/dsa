/** 
 immortalzodd
 24.05.2024 15:31:04
 queueAtSchool
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
    ll n,t; cin>>n>>t;
    string str; cin>>str;
    while(t--){
    	fr(i,1,n){
    		if(str[i]=='G'&&str[i-1]=='B'){
    			swap(str[i],str[i-1]);
    			i++;
    		}
    	}
    }
    cout<<str<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}