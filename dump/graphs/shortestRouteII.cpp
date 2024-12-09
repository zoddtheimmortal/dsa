/** 
 immortalzodd
 29.06.2024 10:51:01
 shortestRouteII
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

ll n,m,q;
vector<vl> arr;

const ll BIG=1e18;

void solve(){
    cin>>n>>m>>q;
    arr.assign(n,vl(n,BIG));
    fr(i,0,m){
    	ll f,s,w; cin>>f>>s>>w;
    	--f; --s;
    	arr[f][s]=arr[s][f]=min(arr[f][s],w);
    }

    fr(i,0,n) arr[i][i]=0;
    fr(k,0,n){
    	fr(i,0,n){
    		fr(j,0,n){
    			arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
    		}
    	}
    }

    while(q--){
    	ll f,s; cin>>f>>s;
    	--f; --s;
    	cout<<(arr[f][s]<BIG?arr[f][s]:-1)<<nL;
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