/**
 immortalZodd
 16.01.2024 22:35:27
**/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

#define pb push_back
#define v(x) vector<x>
#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define rep(i,arr) for(auto i:arr)
#define nL "\n"

void solve(){
	freopen("bcount.in","r",stdin);
	freopen("bcount.out","w",stdout);
	ll n,q; cin>>n>>q;
    vector<vi> arr(3,vi(n,0));
    fr(i,0,n){
    	ll x; cin>>x;
    	arr[x-1][i]=1;
    }

    vector<vl> sum(3,vl(n+1,0));
    sum[0][0]=0,sum[1][0]=0,sum[2][0]=0;

    fr(i,0,3){
    	fr(j,0,n){
    		sum[i][j+1]=sum[i][j]+arr[i][j];
    	}
    }

    while(q--){
    	int l,r; cin>>l>>r;
    	cout<<sum[0][r]-sum[0][l-1]<<" "<<sum[1][r]-sum[1][l-1]<<" "<<sum[2][r]-sum[2][l-1]<<nL;
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