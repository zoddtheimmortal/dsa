/** 
 immortalzodd
 11.07.2024 21:36:38
 petrAndCombinationLock
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
    for(int mask=0;mask<(1<<n);mask++){
    	ll sum=0;
    	for(int i=0;i<n;i++){
    		if((1LL<<i)&mask) sum+=arr[i];
    		else sum-=arr[i];
    	}
    	if(sum%360==0){
    		cout<<"YES"<<nL;
    		return;
    	}
    }
    cout<<"NO"<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}