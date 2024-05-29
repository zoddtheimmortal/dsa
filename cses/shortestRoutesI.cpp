/** 
 immortalzodd
 15.04.2024 12:28:30
 shortestRoutesI
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

#define S 0

void solve(){
    ll n,m; cin>>n>>m;
    vector<vector<pair<int,int>>> arr(n);

    fr(i,0,m){
        ll f,s,w;
        cin>>f>>s>>w;
        arr[--f].push_back({--s,w});
    }

    vl dist(n,LLONG_MAX);
    priority_queue<pair<ll,int>> pq;

    dist[S]=0;
    pq.push({0,S});

    while(!pq.empty()){
        ll cdist=-pq.top().first;
        int v=pq.top().second;
        pq.pop();
        if(cdist!=dist[v]) continue;
        for(auto&x:arr[v]){
            if(cdist+x.second<dist[x.first]){
                dist[x.first]=cdist+x.second;
                pq.push({-(cdist+x.second),x.first});
            }
        }
    }

    for(ll&x:dist) cout<<x<<" ";
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