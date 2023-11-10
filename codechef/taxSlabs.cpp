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
    double n,tax=0; cin>>n;
    n/=(1e5);
    double k=n;
    int i=0;
    while(n-2.5>0&&i<6){
    	n-=2.5;
    	tax+=(2.5*(5*i)*0.01);
    	i++;
    }
    if(n>0) tax+=(n*(5*i)*0.01);
    cout<<(k-tax)*(1e5)<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}