/** 
 immortalzodd
 14.07.2024 23:00:32
 iceSkating
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

const int MXN=1001;
ll n;
vector<vi> arr(MXN,vi(MXN,0));
vector<vi> vis(MXN,vi(MXN,0));

int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};

void dfs(int r,int c){
	vis[r][c]=1;
	fr(i,0,4){
		int p=r+dx[i],q=c+dy[i];
		if(p<0||p>=MXN||q<0||q>=MXN||vis[p][q]||arr[p][q]!=1) continue;
		dfs(p,q);
	}
}

void solve(){
    cin>>n;
    fr(i,0,n){
    	ll f,s; cin>>f>>s;
    	arr[f][s]=1;
    }
    ll ans=-1;
    fr(i,0,MXN){
    	fr(j,0,MXN){
    		if(!vis[i][j]&&arr[i][j]==1){
    			dfs(i,j);
    			ans++;
    		}
    	}
    }
    cout<<ans<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}