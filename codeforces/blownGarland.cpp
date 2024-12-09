/** 
 immortalzodd
 31.05.2024 23:52:27
 blownGarland
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
    string s; cin>>s;
    int n=s.size();
    int idx[4]={0};
    fr(i,0,n){
    	if(s[i]=='R') idx[0]=i%4;
    	if(s[i]=='B') idx[1]=i%4;
    	if(s[i]=='Y') idx[2]=i%4;
    	if(s[i]=='G') idx[3]=i%4;
    }
    int dead[4]={0};
    fr(i,0,n){
    	if(s[i]=='!'){
    		fr(j,0,4) if(idx[j]==i%4) dead[j]++;
    	}
    }
    fr(i,0,4) cout<<dead[i]<<" ";
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