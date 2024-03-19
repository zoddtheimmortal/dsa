#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define nL "\n"

void solve(){
    ll n,k; cin>>n>>k;
    ll prod=1;
    vi arr(n,0); for(auto&x:arr) cin>>x;
    for(auto&x:arr){
    	prod*=x;
    	if(2023LL%x!=0||2023LL%prod!=0){
    		cout<<"NO"<<nL;
    		return;
    	}
    }
    cout<<"YES"<<nL;
    fr(i,0,k){
    	if(i==0){
    		cout<<2023LL/prod<<" ";
    		continue;
    	}
    	cout<<1<<" ";
    }
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