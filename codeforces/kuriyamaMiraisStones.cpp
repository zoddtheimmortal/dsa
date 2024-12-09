/** 
 immortalzodd
 26.06.2024 22:00:51
 kuriyamaMiraisStones
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

ll n,m;
vi arr;

void solve(){
    cin>>n;
    arr.assign(n,0); for(int&x:arr) cin>>x;
    vl PR(n+1,0),sortPR(n+1,0);
    fr(i,0,n) PR[i+1]=PR[i]+arr[i];
    sort(all(arr));
    fr(i,0,n) sortPR[i+1]=sortPR[i]+arr[i];
    cin>>m;
    while(m--){
    	int t,l,r; cin>>t>>l>>r;
    	if(t==1) cout<<PR[r]-PR[l-1]<<nL;
    	if(t==2) cout<<sortPR[r]-sortPR[l-1]<<nL;
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