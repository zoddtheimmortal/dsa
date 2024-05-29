/** 
 immortalzodd
 27.05.2024 22:53:47
 airport
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

void solve(){
    int p,n; cin>>p>>n;
    priority_queue<int> pq_min,pq_max;
    fr(i,0,n){
    	int x; cin>>x;
    	pq_min.push(x);
    	pq_max.push(-x);
    }
    int zmin=0,zmax=0,psg=p;
    while(psg>0&&!pq_min.empty()){
    	int ticket=pq_min.top();
    	pq_min.pop();
    	zmin+=ticket;
    	ticket--;
    	if(ticket>0) pq_min.push(ticket);
    	psg--;
    }
    psg=p;
    while(psg>0&&!pq_max.empty()){
    	int ticket=-pq_max.top();
    	pq_max.pop();
    	zmax+=ticket;
    	ticket--;
    	if(ticket>0) pq_max.push(-ticket);
    	psg--;
    }
    cout<<zmin<<" "<<zmax<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}