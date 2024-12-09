/** 
 immortalzodd
 24.06.2024 18:28:05
 doorsBreakingAndRepairing
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

ll n,x,y;

void solve(){
    cin>>n>>x>>y;
    priority_queue<int,vi,greater<int>> pq;
    fr(i,0,n){
    	int k; cin>>k;
    	pq.push(k);
    }
    int ans=0;
    while(!pq.empty()){
    	int top=pq.top();
    	pq.pop();
    	if(top-x<=0) ans++;
    	else if(y>=x) break;
    	else{
    		pq.push(top-x);
    	}
    	int fortify=pq.top();
    	pq.pop();
    	pq.push(fortify+y);
    }
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