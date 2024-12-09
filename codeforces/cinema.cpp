/** 
 immortalzodd
 25.06.2024 10:10:32
 cinema
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

using pii = pair<int,int>;

ll n,m;
map<int,int> mp;
vector<pii> movies;

bool compare(pii a,pii b){
	if(mp[a.first]==mp[b.first]) return mp[a.second]<mp[b.second];
	return mp[a.first]<mp[b.first];
}

void solve(){
    cin>>n;
    fr(i,0,n){
    	int x; cin>>x;
    	mp[x]++;
    }
    cin>>m;
    movies.resize(m);
    fr(i,0,m){
    	cin>>movies[i].first;
    }
    fr(i,0,m){
        cin>>movies[i].second;
    }
    int ans=0;
    pii maxp={0,0};
    fr(i,0,m){
        if(compare(maxp,movies[i])){
            maxp=movies[i];
            ans=i;
        }
    }
    cout<<ans+1<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}