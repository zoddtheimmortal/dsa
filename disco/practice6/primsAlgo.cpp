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

int getMinVertex(vi weight,int n,v(bool) &visited){
    int minVertex=-1;
    fr(i,0,n){
        if(!visited[i] && ((minVertex==-1)||(weight[i]<weight[minVertex]))){
            minVertex=i;
        }
    }
    return minVertex;
}

int primsAlgo(v(vi) arr,int n){
    v(bool) visited(n,false);
    vi weight(n,INT_MAX);
    weight[0]=0;

    fr(k,0,n-1){
        int minVertex=getMinVertex(weight,n,visited);
        visited[minVertex]=true;
        fr(i,0,n){
            if(!visited[i] && arr[minVertex][i]!=INT_MAX){
                if(weight[i]>arr[minVertex][i]){
                    weight[i]=arr[minVertex][i];
                }
            }
        }
    }

    int cost=0;
    fr(i,0,n) cost+=weight[i];
    return cost;
}

void solve(){
    ll n,e; cin>>n>>e;
    v(vi) arr(n,vi(n,INT_MAX));
    fr(i,0,e){
    	ll f,s,w;
    	cin>>f>>s>>w;
    	arr[f-1][s-1]=w;
        arr[s-1][f-1]=w;
    } 
    cout<<primsAlgo(arr,n)<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}