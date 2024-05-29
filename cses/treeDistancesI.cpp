/** 
 immortalzodd
 11.04.2024 10:51:05
 treeDistancesI
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

int dist[2][200000];
vi arr[200000];
ll n;

int dfs(int x,int p,int d,int i){
    dist[i][x]=d;
    int opt=-1;
    for(auto&y:arr[x]){
        if(y!=p){
            int z=dfs(y,x,d+1,i);
            if(opt==-1||dist[i][z]>dist[i][opt]) opt=z;
        }
    }

    return opt==-1?x:opt;
}

void solve(){
    cin>>n;
    fr(i,0,n-1){
        ll f,s; cin>>f>>s;
        arr[--f].push_back(--s);
        arr[s].push_back(f);
    }

    int u=dfs(0,0,0,0);
    int v=dfs(u,u,0,0);
    dfs(v,v,0,1);

    fr(i,0,n) cout<<max(dist[0][i],dist[1][i])<<" ";
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