#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

using ll=long long;
using vi=vector<int>;

#define pb push_back
#define nL endl
#define rep(it,arr) for(auto it:arr)
#define fr(i,x,y) for(ll i=x;i<y;i++)
#define v(x) vector<x>

vi path;
void markPath(v(vi) arr,int n,int sv,int ev,v(bool) &visited){
	visited[sv]=true;
	if(sv==ev){
		path.pb(sv);
		return;
	}
	fr(i,0,n){
		if(!visited[i] && arr[sv][i]==1){
			markPath(arr,n,i,ev,visited);
		}
		if(!path.empty()) break;
	}
	if(!path.empty()){
		path.pb(sv);
		return;
	}
}

void solve(){
	ll n,e; cin>>n;
	e=n-1;
	v(vi) arr(n,vi(n,0));
	fr(i,0,e){
		ll f,s;
		cin>>f>>s;
		arr[f-1][s-1]=1;
		arr[s-1][f-1]=1;
	}
	ll sv,ev; cin>>sv>>ev;
	v(bool) visited(n,false);

	markPath(arr,n,sv-1,ev-1,visited);
	if(!path.empty()){
		cout<<path.size()<<nL;
		for(int i=path.size()-1;i>=0;i--){
			cout<<path[i]+1<<" ";
		}
	}
	else cout<<-1;
	cout<<nL;
}

int main(){
	ll t=1;
	while(t--){
		solve();
	}
}