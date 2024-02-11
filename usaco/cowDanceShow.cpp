/** 
 immortalZodd
 28.01.2024 22:54:55
 cowDanceShow
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

bool check(vi arr,ll n,ll time_max,ll mid){
	priority_queue<ll,vl,greater<ll>> pq;
	ll i=0,j=0,time;
	while(i<mid && j<n){
		pq.push(arr[j]);
		i++; j++;
	}

	while(!pq.empty()){
		time+=(pq.top()-time);
		pq.pop();
		if(j<n) pq.push(arr[j++]+time);
	}

	return time<=time_max;
}

void solve(){
	freopen("cowdance.in","r",stdin);
	freopen("cowdance.out","w",stdout);
    ll n,t; cin>>n>>t;
    vi arr(n,0); for(auto &x:arr) cin>>x;
	ll si=1,ei=n,ans=0;
    while(si<=ei){
    	ll mid=si+(ei-si)/2;
    	if(check(arr,n,t,mid)){
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