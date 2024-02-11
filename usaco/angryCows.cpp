/** 
 immortalZodd
 29.01.2024 00:03:50
 angryCows
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

/* x at which ur launching doesnt need to be an Xi, can be anywhere in that range */
bool check(vl arr,ll n,ll cows,ll r){
	ll i=0,j=0,k=0,cow=0;
	while(i<n && j<n){
		while(j<n){
			if(arr[j]-arr[i]>2*r){
				i=j;
				break;
			}
			j++;
		}
		cow++;
	}
	return cow<=cows;
}

void solve(){
	freopen("angry.in","r",stdin);
	freopen("angry.out","w",stdout);
    ll n,c; cin>>n>>c;
    vl arr(n,0); for(auto &x:arr) cin>>x;
    sort(all(arr));

    ll si=0,ei=arr[n-1]-arr[0],ans=0;
    while(si<=ei){
    	ll mid=si+(ei-si)/2;
    	if(check(arr,n,c,mid)){
    		ans=mid;
    		ei=mid-1;
    	}else si=mid+1;
    }

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