/** 
 immortalzodd
 23.03.2024 19:15:15
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

void solve(){
    ll n; cin>>n;
    vector<ll> arr(n,0); for(auto&x:arr) cin>>x;
    stack<pair<ll,ll>> ss;

    ll area=0;
    for(int i=0;i<n;i++){
    	int start=i;
    	while(!ss.empty()&&arr[i]<ss.top().second){
    		auto cur=ss.top();
    		start=cur.first;
    		area=max(area,(i-cur.first)*cur.second);
    		ss.pop();
    	}
    	ss.push({start,arr[i]});
    }

    while(!ss.empty()){
    	auto cur=ss.top();
    	ss.pop();
    	area=max(area,(n-cur.first)*cur.second);
    }
    cout<<area<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}