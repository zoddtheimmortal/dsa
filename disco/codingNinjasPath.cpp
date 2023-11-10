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

string str="CODINGNINJA";

bool markDFS(v(v(char)) arr,int n,int e,int sx,int sy,int index,v(v(bool)) &visited){
	if(index>=str.size()) return true;
	visited[sx][sy]=true;
	fr(i,-1,2){
		fr(j,-1,2){
			if((sx+i<n && sx+i>=0) && (sy+j<e && sy+j>=0)){
				if(!visited[sx+i][sy+j] && arr[sx+i][sy+j]==str[index]){
					return markDFS(arr,n,e,sx+i,sy+j,index+1,visited);
				}
			}
		}
	}
	return false;
}

bool getPath(v(v(char)) arr,int n,int e){
	v(v(bool)) visited(n,v(bool)(e,false));
	bool ans=false;
	fr(i,0,n){
		fr(j,0,e){
			if(arr[i][j]==str[0]){
				visited=v(v(bool))(n,v(bool)(e,false));
				ans=markDFS(arr,n,e,i,j,1,visited);
			}
			if(ans) break;
		}
		if(ans) break;
	}
	return ans;
}

void solve(){
     ll n,e; cin>>n>>e;
     v(v(char)) arr(n,v(char)(e));
     fr(i,0,n){
     	fr(j,0,e) cin>>arr[i][j];
     }
     cout<<(getPath(arr,n,e)?"true":"false")<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}