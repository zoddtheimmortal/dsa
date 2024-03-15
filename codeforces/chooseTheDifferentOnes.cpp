/** 
 immortalzodd
 21.02.2024 17:38:19
 chooseTheDifferentOnes
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
    ll n,m,k; cin>>n>>m>>k;
    vi a(n,0),b(m,0);
    for(auto &x:a) cin>>x;
    for(auto &x:b) cin>>x;
    sort(all(a)); sort(all(b));
	
	vi visited(k,0);
	ll i=0,j=0;
	while(i<n && a[i]<=k){
		visited[a[i++]-1]=1;
	}
	while(j<m && b[j]<=k){
		if(visited[b[j]-1]==1) visited[b[j]-1]=3;
		else if(visited[b[j]-1]==0) visited[b[j]-1]=2;
		j++;
	}

	ll c1=0,c2=0;
	for(auto &x:visited){
		if(x==1) c1++;
		else if(x==2) c2++;
		else if(x==3) c1++,c2++;
		else{
			cout<<"NO"<<nL;
			return;
		}
	}
	cout<<((c1>=k/2 && c2>=k/2)?"YES":"NO")<<nL;
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    cin>>t;

    while(t--){
        solve();
    }
}