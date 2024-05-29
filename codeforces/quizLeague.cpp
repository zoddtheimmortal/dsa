/** 
 immortalzodd
 26.05.2024 23:21:04
 quizLeague
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
	ll n,k; cin>>n>>k;
	vi table(n,0); for(int&x:table) cin>>x;
	int i=k-1;
	while(table[i]!=1) i=(i+1)%n;
	cout<<i+1<<nL;
}

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}