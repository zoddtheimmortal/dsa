/** 
 immortalzodd
 24.03.2024 10:23:20
 mikeAndFeet
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
    vi arr(n,0),left(n,-1),right(n,n);
    for(auto &x:arr) cin>>x;
    stack<int> ss;

    for(int i=0;i<n;i++){
    	while(!ss.empty()&&arr[i]<=arr[ss.top()]) ss.pop();
    	if(!ss.empty()) left[i]=ss.top();
    	ss.push(i);
    }

    ss=stack<int>();
    for(int i=n-1;i>=0;i--){
    	while(!ss.empty()&&arr[i]<=arr[ss.top()]) ss.pop();
    	if(!ss.empty()) right[i]=ss.top();
    	ss.push(i);
    }

    vi ans(n+1,0);
    for(int i=0;i<n;i++){
    	int len=right[i]-left[i]-1;
    	ans[len]=max(ans[len],arr[i]);
    }

    for(int i=n-1;i>=0;i--){
    	ans[i]=max(ans[i],ans[i+1]);
    }

    fr(i,1,n+1) cout<<ans[i]<<" ";
    cout<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}