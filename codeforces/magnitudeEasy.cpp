/** 
 immortalzodd
 14.07.2024 17:21:58
 magnitudeEasy
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
#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)

void solve(){
    ll n; cin>>n;
    vi arr(n,0); for(int&x:arr) cin>>x;
    ll sum=0,msum=0;

    for(int&x:arr){
    	sum+=x;
    	msum=min(msum,sum);
    }

    cout<<sum-2*msum<<nL;
}

int main(){
    fast_io;
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}