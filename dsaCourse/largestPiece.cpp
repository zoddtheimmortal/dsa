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

ll temp=1;
void markDFS(v(vi) arr,int n,int sx,int sy,v(v(bool)) &visited){
	visited[sx][sy]=1;
	fr(i,-1,2){
		fr(j,-1,2){
			if((i==0||j==0)&&(sx+i<n && sx+i>=0)&&(sy+j<n && sy+j>=0)){
				if(!visited[sx+i][sy+j] && arr[sx+i][sy+j]==1){
					temp++;
					markDFS(arr,n,sx+i,sy+j,visited);
				}
			}
		}
	}
}

int largestPiece(v(vi) arr,int n){
	v(v(bool)) visited(n,v(bool)(n,false));
	ll ans=0;
	fr(i,0,n){
		fr(j,0,n){
			if(!visited[i][j] && arr[i][j]==1){
				temp=1;
				markDFS(arr,n,i,j,visited);
				ans=max(ans,temp);
			}
		}
	}
	return ans;
}

void solve(){
    ll n; cin>>n;
    v(vi) arr(n,vi(n,0));
    fr(i,0,n){
    	fr(j,0,n) cin>>arr[i][j];
    } 
    cout<<largestPiece(arr,n)<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}