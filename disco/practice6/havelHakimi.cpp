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

bool isSimple(vi arr,int n){
	while(1){
		sort(all(arr),greater<int>());
		if(arr[0]==0) return true;

		int pivot=arr[0];
		arr.erase(arr.begin());

		if(pivot>arr.size()) return false;
		fr(i,0,pivot){
			arr[i]-=1;
			if(arr[i]<0) return false;
		}
	}
}

void solve(){
    ll n; cin>>n;
    vi arr(n,0);
    fr(i,0,n) cin>>arr[i];
    cout<<(isSimple(arr,n)?"YES":"NO")<<nL; 
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}