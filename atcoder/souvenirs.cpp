/** 
 immortalzodd
 17.07.2024 11:41:15
 souvenirs
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

ll n,m;
vi price,candy;

void solve(){
    cin>>n>>m;
    price.resize(n); for(int&x:price) cin>>x;
    candy.resize(m); for(int&x:candy) cin>>x;

    sort(all(price)); sort(all(candy));

    ll i=0,j=0,ans=0;
    while(i<n&&j<m){
    	if(price[i]<candy[j]) i++;
    	else{
    		ans+=price[i];
    		i++;
    		j++;
    	}
    }
    cout<<(j<m?-1:ans)<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}