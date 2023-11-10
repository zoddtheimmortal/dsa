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

// always give reference for a vector if u want to change it
void dfs(vector<vi>& arr,int n,int sv,vector<bool>& visited){
	cout<<sv<<" ";
	visited[sv]=true;
	fr(i,0,n){
		if(i==sv) continue;
		if(arr[sv][i]==1&&!visited[i]){
			dfs(arr,n,i,visited);
		}
	}
}

void solve(){
    int n,e; cin>>n>>e;
    vector<vi> arr(n,vi(n,0));
    fr(i,0,e){
    	int f,s;
    	cin>>f>>s;
    	arr[f][s]=1;
    	arr[s][f]=1;
    }
    vector<bool> visited(n,false);
    dfs(arr,n,0,visited);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}