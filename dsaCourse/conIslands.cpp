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

void markIsland(v(vi) arr,int n,int m,int sx,int sy,v(v(bool)) &visited){
	visited[sx][sy]=true;
	fr(i,-1,2){
		fr(j,-1,2){
			if((sx+i<n && sx+i>=0) && (sy+j<m && sy+j>=0)){
				if(!visited[sx+i][sy+j] && arr[sx+i][sy+j]==1){
					markIsland(arr,n,m,sx+i,sy+j,visited);
				}
			}
		}
	}	
}

int islandGroups(v(vi) arr,int n,int m){
	v(v(bool)) visited(n,v(bool)(m,false));
	ll count=0;
	fr(i,0,n){
		fr(j,0,m){
			if(!visited[i][j] && arr[i][j]==1){
				markIsland(arr,n,m,i,j,visited);
				count++;
			}
		}
	}
	return count;
}

void solve(){
    ll n,m; cin>>n>>m;
    v(vi) arr(n,vi(m,0));
    fr(i,0,n){
    	fr(j,0,m) cin>>arr[i][j];
    } 
    cout<<islandGroups(arr,n,m)<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}