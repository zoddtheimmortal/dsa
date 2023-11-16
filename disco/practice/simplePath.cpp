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
void markPath(v(vi) arr,int n,int sv,int ev,v(bool) &visited){
	if(sv==ev){
		path.pb(ev);
		return;
	}
	visited[sv]=true;
	fr(i,0,n){
		if(!visited[i] && arr[sv][i]==1){
			markPath(arr,n,i,ev,visited);
		}
		if(!path.empty()){
			break;
		}
	}
	if(!path.empty()){
		path.pb(sv);
	}
}

void solve(){
    ll n,e; cin>>n;
    e=n;
    v(vi) arr(n,vi(n,0));
    fr(i,0,e-1){
    	ll f,s;
    	cin>>f>>s;
    	arr[f-1][s-1]=1;
    	arr[s-1][f-1]=1;
    }
    ll sv,ev; cin>>sv>>ev;
    v(bool) visited(n,false);
    markPath(arr,n,sv-1,ev-1,visited);
    int len=path.size();
    cout<<len<<nL;
    rf(i,0,len-1){
    	cout<<path[i]+1<<" ";
    }
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