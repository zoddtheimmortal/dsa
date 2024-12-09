/** 
 immortalzodd
 04.08.2024 22:15:05
 singleElementLeft
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
    ll n,k; cin>>n>>k;
    vi arr(n); for(int&x:arr) cin>>x;

    while(arr.size()>1){
    	ll n=arr.size();
    	multiset<int> ms;
    	ll i=1;
    	vi nwarr;

    	for(int i=0;i<min(k,n);i++) ms.insert(arr[i]);
    	nwarr.push_back(*ms.begin());
    	for(int i=k;i<n;i++){
    		ms.erase(ms.find(arr[i-k]));
    		ms.insert(arr[i]);
    		if(i%2==0) nwarr.push_back(*ms.begin());
    		else nwarr.push_back(*ms.rbegin());
    	}
    	arr=nwarr;
    }
    cout<<arr[0]<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}