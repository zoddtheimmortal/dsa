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

vi subset;
void search(int k,vi arr,ll target,int flag[]){
    if(flag[0]==1) return;
    if(k==arr.size()){
        ll sum=0;
        rep(i,subset){
            sum+=i;
        }
        if(sum==target&&flag[0]==0){
            rep(i,subset){
                cout<<i<<" ";
            }
            cout<<nL;
            flag[0]=1;
            return;
        }
    }
    else{
        subset.pb(arr[k]);
        search(k+1,arr,target,flag);
        subset.pop_back();
        search(k+1,arr,target,flag);
    }
}

void solve(){
    ll n,target; cin>>n>>target;
    vi arr(n); fr(i,0,n) cin>>arr[i];
    int flag[1]={0};
    search(0,arr,target,flag);
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}