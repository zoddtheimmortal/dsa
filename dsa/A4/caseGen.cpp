/** 
 immortalZodd
 11.02.2024 11:17:22
 caseGen
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
	freopen("vidya.in","w",stdout);
    ll n,m; cin>>n>>m;
    cout<<n<<" "<<m<<nL;
    fr(i,0,n){
    	fr(j,0,m){
    		if((i+j)%3==0) cout<<'*';
    		else if((i+j)%5==1) cout<<"o";
    		else cout<<'.';
    	}
    	cout<<nL;
    }
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}