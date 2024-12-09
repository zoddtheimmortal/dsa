/** 
 immortalzodd
 01.06.2024 00:18:17
 antonAndClasses
**/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pi>;

#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define nL "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)

ll n,m;
vpi chess,prog;

void solve(){
	cin>>n; chess.resize(n);
	for(pi&p:chess) cin>>p.first>>p.second;
	cin>>m; prog.resize(m);
	for(pi&p:prog) cin>>p.first>>p.second;

	int a=INT_MAX,b=INT_MAX,c=INT_MIN,d=INT_MIN;
	fr(i,0,n){
		pi p=chess[i];
		a=min(a,p.second);
		c=max(c,p.first);
	}
	fr(i,0,m){
		pi q=prog[i];
		b=min(b,q.second);
		d=max(d,q.first);
	}
	int ans=0;
	ans=max(ans,max(d-a,c-b));
	cout<<ans<<nL;
}

int main(){
	fast_io;
	ll t=1;
    // cin>>t;

	while(t--){
		solve();
	}
}