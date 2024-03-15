/** 
 immortalZodd
 19.02.2024 14:57:23
 thornsAndCoins
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

int n;

int recur_go(string path,int idx,int coins){
	if(idx>=n) return coins;
	if(path[idx]=='*') return coins;
	
	int temp=coins;
	if(path[idx]=='@') temp++;

	return max(recur_go(path,idx+1,temp),recur_go(path,idx+2,temp));
}

void solve(){
    n=0; cin>>n;
    string path; cin>>path;
    int coins=recur_go(path,0,0);
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