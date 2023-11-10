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

int path=0;
void markPath(v(vi) &arr,int n,int m,int sx,int sy,v(v(bool)) &visited){
	visited[sx][sy]=true;
	fr(i,-1,2){
		fr(j,-1,2){
			if((sx+i>=0 && sx+i<n) && (sy+j<m && sy+j>=0)){
				if((i==0||j==0)&&(!visited[sx+i][sy+j])&&(arr[sx+i][sy+j]==1)){
					path++;
					markPath(arr,n,m,sx+i,sy+j,visited);
				}
			}
		}
	}
}


int maxArea(v(vi) arr,int n,int m){
	v(v(bool)) visited(n,v(bool)(m,false));
	int ans=-1;
	fr(i,0,n){
		fr(j,0,m){
			if(!visited[i][j] && arr[i][j]==1){
				path=0;
				markPath(arr,n,m,i,j,visited);
				ans=max(ans,path);
			}
		}
	}
	return ans;
}

void solve(){
    ll n,m; cin>>n>>m;
    v(vi) arr(n,vi(m,0));
    fr(i,0,n){
    	fr(j,0,m){
    		cin>>arr[i][j];
    	}
    } 
    cout<<maxArea(arr,n,m)+1<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}