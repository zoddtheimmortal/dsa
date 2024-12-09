/** 
 immortalzodd
 17.07.2024 22:05:26
 mexMin
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

const int MXN=15e5+5;
ll n,k;
int arr[MXN],cnt[MXN];

void solve(){
    cin>>n>>k;
    fr(i,0,n) cin>>arr[i];
    set<int> st;
    fr(i,0,MXN) st.insert(i);
    fr(i,0,k){
    	cnt[arr[i]]++;
    	if(st.count(arr[i])) st.erase(arr[i]);
    }

    int ans=*st.begin();
    fr(i,k,n){
    	cnt[arr[i-k]]--; cnt[arr[i]]++;
    	if(st.count(arr[i])) st.erase(arr[i]);
    	if(cnt[arr[i-k]]==0) st.insert(arr[i-k]);
    	ans=min(ans,*st.begin());
    }
    cout<<ans<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}