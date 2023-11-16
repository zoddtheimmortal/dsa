#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

#define pb push_back
#define v(x) vector<x>
#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define rep(i,arr) for(auto i:arr)
#define nL "\n"

bool checkSimple(vi arr,int n){
	sort(all(arr),greater<int>());
	int vertex=arr[0];
	if(vertex==0) return true;
	fr(i,0,n){
		if(arr[i]<0) return false;
	}
	arr.erase(arr.begin());
	if(vertex>n-1) return false;
	else{
		fr(i,0,vertex) arr[i]-=1;
	}
	return checkSimple(arr,n-1);
}

void solve(){
    ll n; cin>>n;
    vi arr(n,0);
    fr(i,0,n) cin>>arr[i];
    cout<<(checkSimple(arr,n)?"YES":"NO") <<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}