/** 
 immortalzodd
 27.05.2024 22:48:05
 walkingInTheRain
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

ll n;
vi arr;

void solve(){
    cin>>n;
    arr.assign(n,0); for(int&x:arr) cin>>x;
    int minStep=INT_MAX;
    fr(i,1,n) minStep=min(minStep,max(arr[i],arr[i-1]));
    cout<<min(minStep,min(arr[0],arr[n-1]));
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}