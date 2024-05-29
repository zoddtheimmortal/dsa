/** 
 immortalzodd
 25.05.2024 11:57:03
 reading
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
    ll n,x; cin>>n>>x;
    vector<pair<int,int>> arr(n);
    fr(i,0,n){
    	cin>>arr[i].first;
    	arr[i].second=i;
    }
    sort(all(arr));
    vi times;
    int light=INT_MAX;
    fr(i,0,x){
    	times.push_back(arr[n-i-1].second);
    	light=min(light,arr[n-i-1].first);
    }
    cout<<light<<nL;
    sort(all(times));
    for(int&x:times) cout<<x+1<<" ";
    cout<<nL;
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}