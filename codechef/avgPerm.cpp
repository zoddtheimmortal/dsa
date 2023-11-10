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
    ll n,x=1; cin>>n;
    vi arr(n,0);
    if(n==3){
    	cout<<"3 2 1\n";
    	return;
    }
    arr[0]=n;
    arr[n-1]=n-1;
    arr[n-2]=n-2;
    arr[1]=n-3;
    fr(i,0,n){
    	if(arr[i]==0) arr[i]=x++;
    } 
    rep(it,arr) cout<<it<<" ";
    cout<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}