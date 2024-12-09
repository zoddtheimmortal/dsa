/** 
 immortalzodd
 30.06.2024 23:54:46
 freedomTrail
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

int findRotateSteps(string ring, string key) {
	int n=ring.size(),m=key.size();
	int ans=0,p=0,q=0;

	for(int i=0;i<m;i++){
		int cost=INT_MAX;
		for(int j=0;j<n;j++){
			if(ring[j]==key[i]&&cost>1+min(abs(j-p),n-abs(j-p)-1)){
				cost=1+min(abs(j-p),n-abs(j-p));
				q=j;
			}
		}
		p=q;
		ans+=cost;
	}
	return ans;
}

void solve(){
	string a,b; cin>>a>>b;
	cout<<findRotateSteps(a,b)<<nL;
}

int main(){
	fast_io;
	ll t=1;
    // cin>>t;

	while(t--){
		solve();
	}
}