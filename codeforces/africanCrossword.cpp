/** 
 immortalzodd
 26.05.2024 22:41:54
 africanCrossword
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

ll n,m;
vector<string> arr;

void solve(){
    cin>>n>>m;
    arr.resize(n); for(string&s:arr) cin>>s;
    vector<vi> key(n,vi(m,0));
    fr(i,0,n){
    	fr(j,0,m){
    		fr(p,0,n) key[i][j]=((p!=i&&arr[p][j]==arr[i][j])?1:key[i][j]);
    		fr(q,0,m) key[i][j]=((q!=j&&arr[i][q]==arr[i][j])?1:key[i][j]);
    	}
    }
    fr(i,0,n){
    	fr(j,0,m) if(key[i][j]==0) cout<<arr[i][j];
    }
    cout<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}