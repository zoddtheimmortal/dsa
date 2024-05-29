/** 
 immortalzodd
 12.04.2024 12:11:30
 switchingOnTheLights
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

vector<vi> arr;
ll n,m;

void solve(){
    cin>>n>>m;
    arr=vector<vi>(n,vi(n,0));

    int idx=1;
    fr(i,0,m){
    	ll x,y,a,b;
    	cin>>x>>y>>a>>b;
    	--x,--y,--a,--b;
    	if(arr[x][y]==0) arr[x][y]=idx++;
    	arr[a][b]=arr[x][y];
    }

    fr(i,0,n){
    	fr(j,0,n) cout<<arr[i][j]<<" ";
    	cout<<nL;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}