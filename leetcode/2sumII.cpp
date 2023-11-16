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

void solve(){
    ll n,target; cin>>n>>target;
    vi arr(n,0); fr(i,0,n) cin>>arr[i];
    int si=0,ei=n-1;
    vi path;
    while(si<ei){
    	if(arr[si]+arr[ei]==target){
    		path={si+1,ei+1};
    		break;
    	}
    	else if(arr[si]+arr[ei]<target) si++;
    	else ei--;
    }
    rep(it,path) cout<<it<<" ";
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