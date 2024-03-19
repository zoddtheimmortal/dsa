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

void solve(){
    int n,k; cin>>n>>k;
    vi arr(n); fr(i,0,n) cin>>arr[i];
    bool flag=false;
    ll target=0,bwMax=0,temp=0;
    // fr(i,1,n){
    //     if(arr[i-1]==k) target++;
    //     else if(arr[i-1]==arr[i]){
    //         temp++;
    //     }
    //     else{
    //         temp=1;
    //     }

    //     bwMax=max(bwMax,temp);
    //     if(bwMax<target){
    //         flag=true;
    //         break;
    //     }
    // }
    // if(arr[n-1]==k) target++;
    // if(bwMax<target){
    //         flag=true;
    // }

    fr(i,0,n){
        if(arr[i]==k) target++;
    }
    if(target>0) flag=true;
    cout<<(flag==true?"YES":"NO")<<nL;

}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}