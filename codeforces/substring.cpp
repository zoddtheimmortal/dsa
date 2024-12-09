/** 
 immortalzodd
 08.06.2024 22:12:13
 substring
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
string s;
vector<vi> arr;

void solve(){
    cin>>n>>m>>s;
    arr.resize(n);
    fr(i,0,m){
    	ll f,s; cin>>f>>s;
    	arr[--f].push_back(--s);
    }

    vector<vi> dp(n,vi(26,0));
    vi indeg(n,0);
    fr(i,0,n){
    	for(int&x:arr[i]) indeg[x]++;
    }
	
	queue<int> qs;
	fr(i,0,n){
		if(indeg[i]==0){
			dp[i][s[i]-'a']=1;
			qs.push(i);
		}
	}

	int q=n;
	while(!qs.empty()){
		int v=qs.front();
		qs.pop();
		q--;
		for(int&u:arr[v]){
			fr(k,0,26){
				dp[u][k]=max(dp[u][k],dp[v][k]+(s[u]-'a'==k));
			}
			if(--indeg[u]==0) qs.push(u);
		}
	}

	if(q!=0){
		cout<<-1<<nL;
		return;
	}
	int ans=0;
	fr(i,0,n){
		fr(p,0,26) ans=max(ans,dp[i][p]);
	}
	cout<<ans<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}