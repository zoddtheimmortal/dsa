/** 
 immortalzodd
 27.06.2024 09:09:29
 lectureSleep
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

ll n,k;
vi arr,t;

void solve(){
    cin>>n>>k;
    arr.resize(n); for(int&x:arr) cin>>x;
    t.resize(n); for(int&x:t) cin>>x;

    ll res=0;
    vl PR(n,0);
    fr(i,0,n){
    	if(i) PR[i]+=PR[i-1];
    	if(t[i]==0) PR[i]+=arr[i];
    	else res+=arr[i];
    }

    ll extra=0;
    fr(i,0,n){
    	extra=max(extra,PR[i]-(i-k>=0?PR[i-k]:0));
    }
    cout<<res+extra<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}