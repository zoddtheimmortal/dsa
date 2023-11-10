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

void markDFS(v(vi) arr,int n,int sv,v(bool) &visited){
	visited[sv]=true;
	fr(i,0,n){
		if(!visited[i] && arr[sv][i]==1){
			markDFS(arr,n,i,visited);
		}
	}
}

void markBFS(v(vi) arr,int n,int sv,v(bool) &visited){
	queue<int> qs;
	qs.push(sv);
	visited[sv]=true;
	while(!qs.empty()){
		int vertex=qs.front();
		qs.pop();
		fr(i,0,n){
			if(!visited[i] && arr[vertex][i]==1){
				qs.push(i);
				visited[i]=true;
			}
		}
	}
}

int connectedComp(v(vi) arr,int n){
	v(bool) visited(n,false);
	int count=0;
	fr(i,0,n){
		if(!visited[i]){
			count++;
			markBFS(arr,n,i,visited);
		}
	}
	return count;
}

void solve(){
    ll n,e; cin>>n>>e;
    v(vi) arr(n,vi(n,0));
    fr(i,0,e){
    	ll f,s;
    	cin>>f>>s;
    	arr[f][s]=1;
    	arr[s][f]=1;
    } 
    cout<<connectedComp(arr,n)<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}