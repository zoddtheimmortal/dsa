/** 
 immortalZodd
 28.01.2024 23:32:20
 convention
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

bool check(vl arr,ll n,ll m,ll c,ll time){
	ll prev=0,now=0,bus=0;
	while(now<n){
		if(prev==now) bus++;
		if(arr[now]-arr[prev]>time){
			prev=now;
		}
		else if(now-prev+1==c){
			prev=++now;
		}
		else ++now;
	}
	return bus<=m;
}

void solve(){
	freopen("convention.in","r",stdin);
	freopen("convention.out","w",stdout);

    ll n,m,c; cin>>n>>m>>c;
    vl arr(n,0); for(auto &x:arr) cin>>x;
    sort(all(arr));

    ll si=0,ei=arr[n-1]-arr[0],ans=0;
    while(si<=ei){
    	ll mid=si+(ei-si)/2;
    	if(check(arr,n,m,c,mid)){
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