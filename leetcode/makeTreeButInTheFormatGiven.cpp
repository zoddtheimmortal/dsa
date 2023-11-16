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

vi path;

int getParent(vi parent,int n){
	if(parent[n]==n) return n;
	return getParent(parent,parent[n]);
}

void solve(){
    ll n; cin>>n;
    v(vi) arr(n,vi(2,0));
    fr(i,0,n){
    	cin>>arr[i][0]>>arr[i][1];
    }
    vi parent(n,0);
    vi path;
    fr(i,0,n){
    	parent[i]=i;
    }
    fr(i,0,n){
    	if(!(getParent(parent,arr[i][0]-1)!=getParent(parent,arr[i][1]-1))){
    		path={arr[i][0],arr[i][1]};
    	}
    	else{
    		parent[arr[i][1]-1]=arr[i][0]-1;
    	}
    }

    rep(it,path) cout<<it<<" ";
    cout<<nL;

}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}