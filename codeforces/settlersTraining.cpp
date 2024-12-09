/** 
 immortalzodd
 01.06.2024 09:42:14
 settlersTraining
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
    arr.assign(k+1,0);
    fr(i,0,n){
    	int x; cin>>x; arr[x]++;
    }
    int ans=0;
    while(arr[k]<n){
    	rf(i,1,k){
    		if(arr[i-1]>0){
    			arr[i-1]--;
    			arr[i]++;
    		}
    	}
    	ans++;
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