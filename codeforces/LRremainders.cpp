/** 
 immortalZodd
 19.02.2024 18:33:27
 LRremainders
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

void solve(){
	ll n,m; cin>>n>>m;
	vi arr(n,0); for(auto &x:arr) cin>>x;
	string str; cin>>str;
	ll si=0,ei=0;
	for(auto &x:str) si+=(x=='L');
	ei=si;
	
	ll temp=1;
	vl ans(n,0);
	for(int i=n-1;i>=0;i--){
		if(str[i]=='L'){
			temp=(temp*arr[--si])%m;
		}
		else temp=(temp*arr[ei++])%m;
		ans[i]=temp;
	}

	for(auto &x:ans) cout<<x<<" ";
	cout<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}