/** 
 immortalzodd
 14.07.2024 17:34:47
 boringDay
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

ll n,l,r;
vi arr;

void solve(){
    cin>>n>>l>>r;
    arr.resize(n); for(int&x:arr) cin>>x;
    int si=0,ei=0,ans=0,cur=0;
    while(si<n){
    	while(ei<n&&cur<l){
    		cur+=arr[ei++];
    	}
    	if(cur>=l&&cur<=r){
    		ans++;
    		si=ei;
    		cur=0;
    	}
    	else{
    		cur-=arr[si];
    		si++;
    	}
    }
    cout<<ans<<nL;
}

int main(){
    fast_io;
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}