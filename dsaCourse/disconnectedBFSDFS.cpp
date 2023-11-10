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

void printDFS(vector<vi>& arr,int n,int sv,vector<bool>& visited){
	cout<<sv<<" ";
	visited[sv]=true;
	fr(i,0,n){
		if(i==sv) continue;
		if(arr[sv][i]==1&&!visited[i]){
			printDFS(arr,n,i,visited);
		}
	}
}

void printBFS(vector<vi>& arr,int n,int sv,vector<bool>& visited){
	queue<int> qs;
	qs.push(sv);
	visited[sv]=true;
	while(!qs.empty()){
		int vertex=qs.front();
		cout<<vertex<<" ";
		qs.pop();
		fr(i,0,n){
			if(i==vertex) continue;
			if(arr[vertex][i]==1 && !visited[i]){
				qs.push(i);
				visited[i]=true;
			}
		}
	}
}

void dfs(vector<vi>&arr,int n){
	vector<bool> visited(n,false);
	fr(i,0,n){
		if(!visited[i]){
			printDFS(arr,n,i,visited);
		}
	}

}

void bfs(vector<vi>&arr,int n){
	vector<bool> visited(n,false);
	fr(i,0,n){
		if(!visited[i]){
			printBFS(arr,n,i,visited);
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

    cout<<"DFS\n";
    dfs(arr,n);
    cout<<nL;
    cout<<"BFS\n";
    bfs(arr,n);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}