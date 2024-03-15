/** 
 immortalZodd
 18.02.2024 21:48:44
 makeEqual
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

ll n,sum=0;

bool check(vi arr){
	for(auto &x:arr){
		if(x!=sum) return false;
	}
	return true;
}

void solve(){
	sum=0; cin>>n;
    vi arr(n,0); for(auto &x:arr){ cin>>x; sum+=x;}
    sum/=n;
    ll si=0,ei=0;
    while(si<n && ei<n){
    	while(ei<n && (arr[ei]>=sum || si>=ei)) ei++;

    	if(ei<n && si<n){
    		ll pour=max(0LL,arr[si]-sum);
    		arr[si]-=pour;
    		arr[ei]+=pour;
    		si++;
    	}
    }
    ll ans=check(arr);
    cout<<(ans?"YES":"NO")<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
  	ll t;cin>>t;

    while(t--){
        solve();
    }
}