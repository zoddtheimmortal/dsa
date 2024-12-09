/** 
 immortalzodd
 01.07.2024 15:16:16
 advertisement
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

using pii = pair<int,int>;

ll n;
vi arr;

void solve(){
    cin>>n;
    arr.resize(n); for(int&x:arr) cin>>x;
    stack<pii> ss;

    ll ans=0;
    fr(i,0,n){
    	int start=i;
    	while(!ss.empty()&&arr[i]<ss.top().second){
    		auto[idx,val]=ss.top();
    		ss.pop();
    		start=idx;
    		ans=max(ans,(i-idx)*val);
    	}
    	ss.push({start,arr[i]});
    }

    while(!ss.empty()){
    	auto[idx,val]=ss.top();
    	ss.pop();
    	ans=max(ans,(n-idx)*val);
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