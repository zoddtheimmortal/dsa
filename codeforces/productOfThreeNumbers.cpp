/** 
 immortalzodd
 25.06.2024 23:29:30
 productOfThreeNumbers
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
	set<int> div;
	for(int i=2;i*i<=n;i++){
		if(n%i==0&&!div.count(i)){
			n/=i;
			div.insert(i);
			break;
		}
	}

	for(int i=2;i*i<=n;i++){
		if(n%i==0&&!div.count(i)){
			n/=i;
			div.insert(i);
			break;
		}
	}

	if((int)div.size()<2||n==1||div.count(n)){
		cout<<"NO"<<nL;
	}
	else{
		cout<<"YES"<<nL;
		div.insert(n);
		for(int x:div) cout<<x<<" ";
		cout<<nL;
	}
}

int main(){
    fast_io;
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}