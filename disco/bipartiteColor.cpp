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

bool isBipartite(vector<vi> arr,int n,int sv){
	vi colorArr(n,-1);
	colorArr[sv]=1;
	queue<int> qs;
	qs.push(sv);

	while(!qs.empty()){
		int vertex=qs.front();
		qs.pop();
		fr(i,0,n){
			if(arr[vertex][i]==1 && colorArr[i]==-1){
				colorArr[i]=1-colorArr[vertex];
				qs.push(i);
			}
			else if(arr[vertex][i]==1 && colorArr[vertex]==colorArr[i]){
				return false;
			}
		}
	}
	return true;
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
    cout<<(isBipartite(arr,n,0)?"YES":"NO")<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}