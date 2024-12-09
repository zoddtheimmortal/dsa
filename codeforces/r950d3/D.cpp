/** 
 immortalzodd
 03.06.2024 20:49:44
 D
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

int gcd(int a,int b){
	if(a==0) return b;
	return gcd(b%a,a);
}

void solve(){
    ll n; cin>>n;
    vi arr(n,0); for(int&x:arr) cin>>x;
    vi g(n-1);
    fr(i,1,n) g[i-1]=gcd(arr[i],arr[i-1]);
    bool dec=true;
    fr(i,1,n) dec&=(g[i]>=g[i-1]);
    if(dec){
    	cout<<"YES"<<nL;
    	return;
    }
    fr(i,1,n-2){
    	bool left=true,right=true;
    	if(g[i]>g[i+1]&&i+2<n){
    		int k=gcd(arr[i],arr[i+2]);
    		if(i-1>=0) left&=(g[i-1]<=k);
    		if(i-2>=0) right&=(g[i+2]>=k);
    		if(left&&right){
    			cout<<arr[i+1]<<nL;
    			cout<<"YES"<<nL;
    			return;
    		}
    	}
    }
    cout<<"NO"<<nL;
}

int main(){
    fast_io;
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}