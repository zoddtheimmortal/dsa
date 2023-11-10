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

void markDFS(vector<vi> &arr,int n,int sv,vector<bool> &visited){
	visited[sv]=true;
	fr(i,0,n){
		if(i==sv) continue;
		if(!visited[i] && arr[sv][i]==1){
			markDFS(arr,n,i,visited);
		}
	}
}

int conComp(vector<vi> arr,int n){
	vector<bool> visited(n,false);
	ll count=0;
	fr(i,0,n){
		if(!visited[i]){
			count++;
			markDFS(arr,n,i,visited);
		}
	}
	return count;
}

void solve(){
     ll n,e; cin>>n>>e;
     vector<vi> arr(n,vi(n,0));
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