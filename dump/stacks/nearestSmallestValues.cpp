/** 
 immortalzodd
 01.07.2024 09:13:36
 nearestSmallestValues
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
    stack<int> ss;
    vi ans(n,0);

    fr(i,0,n){
    	while(!ss.empty()&&arr[i]<=arr[ss.top()]) ss.pop();
    	ans[i]=ss.empty()?0:ss.top()+1;
    	ss.push(i);
    }
    for(int&x:ans) cout<<x<<" ";
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