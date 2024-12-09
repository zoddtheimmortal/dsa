/** 
 immortalzodd
 25.08.2024 14:19:21
 countingDivisorsSieve
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

const int MXN=1e6+5;
int max_div[MXN]={0};

void preprocess(){
	for(int i=2;i<=MXN;i++){
		if(max_div[i]==0){
			for(int j=i;j<=MXN;j+=i) max_div[j]=i;
		}
	}
}

void solve(){
	ll x; cin>>x;
	ll ndiv=1;

	while(x!=1){
		ll div=max_div[x];
		ll cnt=0;

		while(x%div==0){
			cnt++;
			x/=div;
		}

		ndiv*=(1+cnt);
	}

	cout<<ndiv<<nL;
}

int main(){
	preprocess();

    fast_io;
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}