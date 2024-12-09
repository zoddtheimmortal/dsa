/** 
 immortalzodd
 27.07.2024 21:05:18
 speed
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

bool check(int a,int b,int s){
	if(a==0||b==0) return false;
	while(a<b) a*=s;
	return a==b;
}

void solve(){
	int n,s; cin>>n>>s;
    vi arr(n); for(int&x:arr) cin>>x;
    sort(all(arr));

    ll ans=0;
    fr(i,0,n){
    	fr(j,i+1,n){
    		ans+=check(arr[i],arr[j],s);
    	}
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