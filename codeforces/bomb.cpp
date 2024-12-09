/** 
 immortalzodd
 04.08.2024 10:53:52
 bomb
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

using pii = pair<int,int>;

void solve(){
    ll n,k; cin>>n>>k;
    vi arr(n),brr(n);
    for(int&x:arr) cin>>x;
    for(int&x:brr) cin>>x;

    priority_queue<pii> pq;
	fr(i,0,n) pq.push({arr[i],i});

	ll ans=0;
	fr(i,0,k){
		auto[score,idx]=pq.top();
		if(score==0) break;
		pq.pop();
		ans+=score;
		pq.push({max(0,score-brr[idx]),idx});
	}
	cout<<ans<<nL;
}

int main(){
    fast_io;
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}