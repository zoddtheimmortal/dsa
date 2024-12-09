/** 
 immortalzodd
 04.06.2024 23:17:23
 journey
**/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define nL "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)

#define P 10

ll n;
vector<vi> arr;
vector<bool> visited;
double ans=0;

void dfs(int x,int d,double p){
	visited[x]=true;
    int paths=0;
	for(int&y:arr[x]){
		if(!visited[y]) paths++;
	}
    if(paths==0){
        ans+=p*d;
    }
    else{
        double newp=p/paths;
        for(int&y:arr[x]){
            if(!visited[y]) dfs(y,d+1,newp);
        }
    }
}

void solve(){
    cin>>n;
    arr.resize(n);
    fr(i,0,n-1){
    	ll f,s; cin>>f>>s;
    	arr[--f].push_back(--s);
    	arr[s].push_back(f);
    }
    visited.assign(n,false);
    dfs(0,0,1);
    cout<<setprecision(P)<<ans<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}