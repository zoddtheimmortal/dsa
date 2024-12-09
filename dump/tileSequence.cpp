/** 
 immortalzodd
 07.08.2024 22:17:06
 tileSequence
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
	int n; cin>>n;
    vector<string> arr(n);
    for(string&s:arr) cin>>s;

    

	int ans=0;
	if(rg||gr){
		ans=rr+gg+2*min(rg,gr)+(rg!=gr);
	}else ans=max(rr,gg);

	cout<<ans<<nL;
}

void solve2(){

	int n; cin>>n;
    vector<string> arr(n);
    for(string&s:arr) cin>>s;

    sort(all(arr));
	vi dp(n,1);
	
	fr(i,1,n){
		fr(j,0,i){
			if(dp[i]<1+dp[j]&&(arr[i][0]==arr[j][1]||arr[i][1]==arr[j][0])){
				dp[i]=1+dp[j];
			}
		}
	}

	int ans=0;
	for(int&x:dp) ans=max(ans,x);
	cout<<ans<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        // solve();
        solve2();
    }
}