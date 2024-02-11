/** 
 immortalZodd
 05.02.2024 14:12:21
 moocast
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

ll nodes=0;
void dfs(vi arr[],ll sv,vector<bool> &visited){
    if(visited[sv]) return;

    visited[sv]=true;
    nodes++;

    for(auto &x:arr[sv]){
        dfs(arr,x,visited);
    }
}

void solve(){
    freopen("moocast.in","r",stdin);
    freopen("moocast.out","w",stdout);
    ll n; cin>>n;
    vector<vi> arr(n,vi(3,0));
    fr(i,0,n) cin>>arr[i][0]>>arr[i][1]>>arr[i][2];

    /* create your adj list based on if each cow is reachable or not,
        then just find max using dfs */

    vi node[n];
    fr(i,0,n){
        ll x1=arr[i][0],y1=arr[i][1],p=arr[i][2];
        fr(j,0,n){
            ll x2=arr[j][0],y2=arr[j][1];
            double dist=(((x1-x2)*(x1-x2))+((y2-y1)*(y2-y1)));
            if(dist<=p*p){
                node[i].push_back(j);
            }
        }
    }

    ll ans=0;
    vector<bool> visited(n,false);

    fr(i,0,n){
        nodes=0;
        fill(all(visited),false);

        dfs(node,i,visited);
        ans=max(ans,nodes);
    }

    cout<<ans<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}