/** 
 immortalzodd
 29.02.2024 10:19:16
 moocastCost
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

ll n;
vi x,y;

ll dis(ll i,ll j){
	ll dx=x[i]-x[j];
	ll dy=y[i]-y[j];
	return dx*dx+dy*dy;
}

bool check(ll power){
	queue<int> qs;
	vector<bool> visited(n,false);
	qs.push(0);
	visited[0]=true;

	while(!qs.empty()){
		int vertex=qs.front();
		qs.pop();
		fr(i,0,n){
			if(!visited[i]&&dis(i,vertex)<=power){
				qs.push(i);
				visited[i]=true;
			}
		}
	}

	for(bool b:visited) if(!b) return false;

	return true;
}

void solve(){
	freopen("moocast.in","r",stdin);
	freopen("moocast.out","w",stdout);
	cin>>n;
	x.resize(n); y.resize(n);
	fr(i,0,n) cin>>x[i]>>y[i];

	ll si=0,ei=INT_MAX,ans=0;
	while(si<=ei){
		ll mid=si+(ei-si)/2;
		if(check(mid)){
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