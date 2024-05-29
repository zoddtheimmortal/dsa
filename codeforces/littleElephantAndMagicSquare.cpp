/** 
 immortalzodd
 28.05.2024 09:10:03
 littleElephantAndMagicSquare
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
    vector<vi> arr(3,vi(3,0));
    fr(i,0,3){
        fr(j,0,3) cin>>arr[i][j];
    }
    int x=0,y=0,z=0;
    x=arr[2][1]+arr[2][0]-(arr[0][1]+arr[0][2])+arr[1][0]+arr[1][2];
    y=arr[2][1]+arr[2][0]+(arr[0][1]+arr[0][2])-(arr[1][0]+arr[1][2]);
    z=-(arr[2][1]+arr[2][0])+(arr[0][1]+arr[0][2])+arr[1][0]+arr[1][2];
    x/=2; y/=2; z/=2;
    arr[0][0]=x; arr[1][1]=y; arr[2][2]=z;
    fr(i,0,3){
        fr(j,0,3) cout<<arr[i][j]<<" ";
        cout<<nL;
    }
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}