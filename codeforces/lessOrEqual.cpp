/** 
 immortalzodd
 06.06.2024 17:30:07
 lessOrEqual
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
vi arr;

void solve(){
    cin>>n>>k;
    arr.assign(n,0); for(int&x:arr) cin>>x;
    sort(all(arr));
    if(k==0){
    	if(1<arr[0]){
    		cout<<1<<nL;
    	}else cout<<-1<<nL;
    	return;
    }
    if(arr[k-1]==arr[k]){
    	cout<<-1<<nL;
    	return;
    }
    cout<<arr[k-1]<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}