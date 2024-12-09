/** 
 immortalzodd
 03.06.2024 20:11:55
 B
**/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int,int>;

#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define nL "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)

bool compare(pii a,pii b){
	if(a.first==b.first) return a.second<b.second;
	return a.first>b.first;
}

void solve(){
    ll n,f,k; cin>>n>>f>>k;
    vector<pii> arr(n); 
    fr(i,0,n){
    	cin>>arr[i].first;
    	arr[i].second=i;
    }
    int initv=arr[f-1].first;
    sort(all(arr),compare);
    int all=0,now=0;
    fr(i,0,n) all+=(arr[i].first==initv);
    fr(i,k,n) now+=(arr[i].first==initv);
    if(all==now) cout<<"NO"<<nL;
    else if(now>0) cout<<"MAYBE"<<nL;
    else cout<<"YES"<<nL;
}

int main(){
    fast_io;
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}