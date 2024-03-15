/** 
 immortalZodd
 12.02.2024 11:42:01
 appleDivisionRecur
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

vi arr(21);
ll n;

ll recur_div(ll idx,ll sum1,ll sum2){
	if(idx==n) return abs(sum1-sum2);

	return min(recur_div(idx+1,sum1+arr[idx],sum2),recur_div(idx+1,sum1,sum2+arr[idx]));
}

void solve(){
	cin>>n;
	arr.resize(n);
	for(auto &x:arr) cin>>x;

	ll ans=recur_div(0,0,0);
	cout<<ans<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}