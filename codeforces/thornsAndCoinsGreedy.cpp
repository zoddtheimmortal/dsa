/** 
 immortalZodd
 19.02.2024 15:04:01
 thornsAndCoinsGreedy
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

void solve(){
    int n; cin>>n;
    string path; cin>>path;
    int coins=0,i=0,flag=0;
    while(i<n){
    	if(path[i]=='@') coins++;
    	if(i+2<n && path[i+1]=='*' && path[i+2]=='*') break;
    	if(i+1<n && path[i+1]=='*') i++;

    	i++;
    }
    cout<<coins<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}