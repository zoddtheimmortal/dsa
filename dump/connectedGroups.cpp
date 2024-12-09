/** 
 immortalzodd
 05.08.2024 14:29:41
 connectedGroups
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

int vis[305][305]={0};
int n;
vector<vi> arr;
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

void dfs(int r,int c){
	vis[r][c]=1;
	fr(i,0,4){
		int p=r+dx[i],q=c+dy[i];
		if(p<0||p>=n||q<0||q>=n||vis[p][q]||arr[p][q]!=1) continue;
		dfs(p,q);
	}
}

void solve(){
	cin>>n;
    arr.assign(n,vi(n,0));
    fr(i,0,n){
    	fr(j,0,n) cin>>arr[i][j];
    }

    ll ans=0;
    fr(i,0,n){
    	fr(j,0,n){
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