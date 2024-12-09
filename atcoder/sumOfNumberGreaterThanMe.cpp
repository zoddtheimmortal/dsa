/** 
 immortalzodd
 17.07.2024 17:14:06
 sumOfNumberGreaterThanMe
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

using pii = pair<ll,ll>;

void solve(){
    ll n; cin>>n;
    vector<pii> arr(n);
    fr(i,0,n){
    	ll x; cin>>x;
    	arr[i]={x,i};
    }
    sort(all(arr));
    vector<pii> ans;
    vl pfix(n+1,0);
    fr(i,0,n) pfix[i+1]=pfix[i]+arr[i].first;

    ll i=0,j=0;
    while(j<n){
    	while(i<n&&arr[i].first<=arr[j].first) i++;
    	ll sum=pfix[n]-pfix[i];
    	ans.push_back({arr[j].second,sum});
    	j++;
    }
    sort(all(ans));
    for(pii&p:ans) cout<<p.second<<" ";
    cout<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}