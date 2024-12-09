/** 
 immortalzodd
 12.07.2024 18:56:58
 companyQueriesI
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

const int MXN=2e5+5,MXE=log2(MXN)+1;
int up[MXN][MXE];
ll n,q;

void solve(){
    cin>>n>>q;
    memset(up,-1,sizeof(up));
    fr(i,2,n+1) cin>>up[i][0];

    fr(i,1,MXE){
    	fr(j,1,n+1){
    		if(up[j][i-1]!=-1) up[j][i]=up[up[j][i-1]][i-1];
    	}
    }

    while(q--){
    	ll x,k; cin>>x>>k;
    	fr(i,0,MXE){
    		if(k&(1<<i)){
    			x=up[x][i];
    			if(x==-1) break;
    		}
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