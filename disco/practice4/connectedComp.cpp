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

void markPath(v(vi) arr,int n,int sv,v(bool) &visited){
	visited[sv]=true;
	fr(i,0,n){
		if(!visited[i] && arr[sv][i]==1){
			markPath(arr,n,i,visited);
		}
	}
}

int conComp(v(vi) arr,int n){
	int comp=0;
	v(bool) visited(n,false);
	fr(i,0,n){
		if(!visited[i]){
			comp++;
			markPath(arr,n,i,visited);
		}
	}
	return comp;
}

void solve(){
    ll n,e;
    cin>>n>>e;
    v(vi) arr(n,vi(n,0));
    fr(i,0,e){
    	ll f,s;
    	cin>>f>>s;
    	arr[f-1][s-1]=1;
    	arr[s-1][f-1]=1;
    } 
    cout<<conComp(arr,n)<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}