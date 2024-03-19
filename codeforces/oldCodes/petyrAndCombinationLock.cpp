/** 
 immortalZodd
 31.01.2024 11:17:19
 petyrAndCombinationLock
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

bool check(vi arr,ll n){
	ll rot=0;
	for(ll mask=0;mask<(1<<n);mask++){
		rot=0;
		fr(i,0,n){
			if(mask&(1<<i)){
				rot+=arr[i];
			}else rot-=arr[i];
		}
		if(rot%360==0) return true;
	}
	return false;
}

void solve(){
    ll n; cin>>n;
    vi arr(n,0); fr(i,0,n) cin>>arr[i];

    bool ans=check(arr,n);
    cout<<(ans?"YES\n":"NO\n");
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}