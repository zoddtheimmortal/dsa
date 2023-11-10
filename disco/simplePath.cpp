#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

#define pb push_back
#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define rep(i,arr) for(auto i:arr)
#define nL "\n"

vi path;
void pathDFS(vector<vi> arr,int n,int sv,int ev,vector<bool> visited){
	visited[sv]=true;
	if(sv==ev){
		path.pb(sv);
		return;
	}
	fr(i,0,n){
		if(!visited[i] && arr[sv][i]==1){
			pathDFS(arr,n,i,ev,visited);
			if(!path.empty()) break;
		}
	}
	if(!path.empty()){
		path.pb(sv);
		return;
	}
}

void solve(){
	ll n,e; cin>>n;
	e=n-1;
	vector<vi> arr(n,vi(n,0));
	fr(i,0,e){
		ll f,s;
		cin>>f>>s;
		arr[f-1][s-1]=1;
		arr[s-1][f-1]=1;
	}

	int sv,ev; cin>>sv>>ev;
	sv-=1,ev-=1;

	vector<bool> visited(n,false);
	pathDFS(arr,n,sv,ev,visited);
	if(path.empty()) cout<<-1;
	else{
		cout<<path.size()<<nL;
		rf(i,0,path.size()-1) cout<<path[i]+1<<" ";
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