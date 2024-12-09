/** 
 immortalzodd
 17.08.2024 09:45:47
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

    vi indeg(n,0);
    fr(i,0,n){
    	for(int&x:arr[i]) indeg[x]++;
    }
	
	ll cnt=n;
	vector<vi> dp(n,vi(26,0));
	queue<int> qs;
	fr(i,0,n){
		if(indeg[i]==0){
			qs.push(i);
			cnt--;
			dp[i][s[i]-'a']=1;
		}
	}

	while(!qs.empty()){
		int v=qs.front();
		qs.pop();

		for(int&u:arr[v]){
			fr(i,0,26){
				dp[u][i]=max(dp[u][i],dp[v][i]);
			}
			if(--indeg[u]==0){
				qs.push(u);
				dp[u][s[u]-'a']++;
				cnt--;
			}
		}
	}

	if(cnt>0) cout<<-1<<nL;
	else{
		ll ans=0;
		fr(i,0,n){
			fr(j,0,26) ans=max<ll>(ans,dp[i][j]);
		}

		cout<<ans<<nL;
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