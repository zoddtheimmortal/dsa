/** 
 immortalzodd
 23.07.2024 22:38:15
 teamwork
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

ll n,k;
vl tree;
const int MXN=1e4+5;
ll dp[MXN]={0};

void add(int k,ll x){
	k+=n;
	tree[k]=x;
	for(;k>1;k/=2){
		tree[k/2]=max(tree[k],tree[k^1]);
	}
}

ll query(int a,int b){
	ll ans=0;
	for(a+=n,b+=n;a<b;a/=2,b/=2){
		if(a%2==1) ans=max(ans,tree[a++]);
		if(b%2==1) ans=max(ans,tree[--b]);
	}
	return ans;
}

void solve(){
    cin>>n>>k;
    tree.assign(2*n,0);
    fr(i,0,n){
    	ll x; cin>>x;
    	add(i,x);
    }

    fr(i,1,n+1){
    	fr(j,1,k+1){
    		if(i-j>=0) dp[i]=max(dp[i],dp[i-j]+query(i-j,i)*j);
    	}
    }
    cout<<dp[n]<<nL;
}

int main(){
    fast_io;
    ll t=1;
    freopen("teamwork.in","r",stdin);
    freopen("teamwork.out","w",stdout);
    // cin>>t;

    while(t--){
        solve();
    }
}