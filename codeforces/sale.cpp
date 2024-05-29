/** 
 immortalzodd
 24.05.2024 15:35:49
 sale
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
	int n,m; cin>>n>>m;
	vi arr(n,0); for(int&x:arr) cin>>x;
	sort(all(arr));
	int ans=0;
	for(int i=0;i<m&&arr[i]<=0;i++) ans+=arr[i];
	cout<<-ans<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}