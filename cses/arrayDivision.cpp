/** 
 immortalZodd
 28.01.2024 11:40:15
 arrayDivision
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

/* binary search from 0 to sum of all elements, then check if it's possible
	to make k subarrays from that */
bool check(vi arr,ll n,ll k,ll mid){
	ll count=0;
	ll i=0,temp=0;
	while(i<n){
		temp+=arr[i];
		if(temp>mid){
			temp=arr[i];
			if(temp>mid) return false;
			count++;
		}
		i++;
	}
	if(temp<=mid) count++;
	return count<=k;
}

void solve(){
    ll n,k; cin>>n>>k;
    vi arr(n,0);
    ll max_sum=0;
    for(auto &x:arr){
    	cin>>x;
    	max_sum+=x;
    }

    ll si=0,ei=max_sum,ans=0;
    while(si<=ei){
    	ll mid=si+(ei-si)/2;
    	if(check(arr,n,k,mid)){
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