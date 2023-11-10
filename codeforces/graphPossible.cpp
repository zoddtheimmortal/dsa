#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

#define pb push_back
#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define rep(i,arr) for(auto i:arr)
#define nL "\n"

bool check(vi arr){
	sort(all(arr),greater<int>());
	int x=arr[0];
	arr.erase(arr.begin());
	fr(i,0,x){
		arr[i]-=1;
	}
	
	bool flag=true;
	rep(i,arr){
		if(i<0) return false;
		if(i>0) flag=false;
	}
	if(flag) return true;
	else return check(arr);
}

void solve(){
    int n; cin>>n;
    vi arr(n); fr(i,0,n) cin>>arr[i];
    cout<<(check(arr)?"YES":"NO")<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}