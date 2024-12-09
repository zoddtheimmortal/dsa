/** 
 immortalzodd
 24.06.2024 19:50:48
 birthday
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
    arr.resize(n); for(int&x:arr) cin>>x;
    sort(all(arr));
    for(int i=0;i<n;i++){
        if(i%2==0) cout<<arr[i]<<" ";
    }
    int next=(n-1%2!=0?n-1:n-2);
    for(int i=next;i>=0;i--){
        if(i%2!=0) cout<<arr[i]<<" ";
    }
    cout<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}