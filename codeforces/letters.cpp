/** 
 immortalzodd
 02.06.2024 18:59:01
 letters
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
vl rooms,letters,prefix;

ll search(ll x){
	ll si=0,ei=n,ans=0;
	while(si<=ei){
		ll mid=si+(ei-si)/2;
        if(prefix[mid]>=x){
            ans=mid;
            ei=mid-1;
        }else si=mid+1;
	}
    return ans;
}

void solve(){
    cin>>n>>m;
    rooms.assign(n,0); letters.assign(m,0);
    for(ll&x:rooms) cin>>x;
    for(ll&x:letters) cin>>x;
    prefix.assign(n+1,0);
    fr(i,1,n+1) prefix[i]=prefix[i-1]+rooms[i-1];

    for(ll&x:letters){
        ll dorms=search(x);
        ll room=x-prefix[dorms-1];
        cout<<dorms<<" "<<room<<nL;
    }
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}