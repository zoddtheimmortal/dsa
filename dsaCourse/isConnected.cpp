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

bool isConnected(vector<vi> arr,int n,int sv){
	queue<int> qs;
	vector<bool> visited(n,false);
	visited[sv]=true;
	qs.push(sv);
	while(!qs.empty()){
		int vertex=qs.front();
		qs.pop();
		fr(i,0,n){
			if(arr[vertex][i]==1 && !visited[i]){
				qs.push(i);
				visited[i]=true;
			}
		}
	}
	sort(all(visited));
	if(binary_search(all(visited),false)) return false;
	else return true;
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
    cout<<(isConnected(arr,n,0)?"true":"false")<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}