/** 
 immortalzodd
 12.07.2024 14:37:35
 planetsQueriesI
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

const int MXN=2e5+5,MXE=30;
ll n,q;
int parent[MXN][MXE];

void solve(){
    cin>>n>>q;
    fr(i,1,n+1) cin>>parent[i][0];

    fr(i,1,MXE){
    	fr(j,1,n+1) parent[j][i]=parent[parent[j][i-1]][i-1];
    }

    while(q--){
    	int x,k; cin>>x>>k;
    	fr(i,0,MXE){
    		if(k&(1<<i)) x=parent[x][i];
    	}
    	cout<<x<<nL;
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