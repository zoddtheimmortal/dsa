/** 
 immortalzodd
 18.03.2024 11:50:06
 arrayFix
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

void solve(){
    ll n; cin>>n;
    vi arr(n,0); for(auto &x:arr) cin>>x;
    vi b({arr[n-1]});
    for(int i=n-2;i>=0;i--){
    	if(arr[i]>b.back()){
    		b.push_back(arr[i]%10);
    		b.push_back(arr[i]/10);
    	}
    	else b.push_back(arr[i]);
    }
    cout<<(is_sorted(b.rbegin(),b.rend())?"YES":"NO")<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}