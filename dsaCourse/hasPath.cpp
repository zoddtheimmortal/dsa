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

bool findPathBFS(vector<vi> arr,int n, int sv,int ev){
	vector<bool> visited(n,false);
	queue<int> qs;
	qs.push(sv);
	visited[sv]=true;
	while(!qs.empty()){
		int vertex=qs.front();
		qs.pop();
		fr(i,0,n){
			if(arr[vertex][i]==1 && !visited[i]){
				qs.push(i);
				visited[i]=true;
				if(i==ev) return true;
			}
		}

	}
	return false;

}

void findPathDFS(vector<vi> &arr,int n, int sv,vector<bool> &visited){
	visited[sv]=true;
	fr(i,0,n){
		if(i==sv) continue;
		if(!visited[i] && arr[sv][i]==1){
			findPathDFS(arr,n,i,visited);
		}
	}
}

void solve(){
     ll n,e; cin>>n>>e;
     vector<vi> arr(n,vi(n,0));
     fr(i,0,e){
     	ll f,s;
     	cin>>f>>s;
     	arr[f][s]=1;
     	arr[s][f]=1;
     }
     ll sv,ev; cin>>sv>>ev;
     // cout<<(findPathBFS(arr,n,sv,ev)?"true":"false")<<nL;

     vector<bool> visited(n,false);
     findPathDFS(arr,n,sv,visited);
     cout<<(visited[ev]?"true":"false")<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}