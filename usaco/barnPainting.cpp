/** 
 immortalzodd
 26.07.2024 22:29:47
 barnPainting
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

const int MOD=1e9+7;
const int MXN=1e5+5;
int n,k;
ll dp[MXN][3];
vi arr[MXN];

void dfs(int x,int p){
	for(int&y:arr[x]){
		if(y!=p){
			dfs(y,x);
			fr(c,0,3){
				int p=(c+1)%3,q=(c+2)%3;
				dp[x][c]*=(dp[y][p]+dp[y][q]);
				dp[x][c]%=MOD;
			}
		}
	}
}

void solve(){
    cin>>n>>k;
    fr(i,0,n-1){
    	ll f,s; cin>>f>>s;
    	arr[f].push_back(s);
    	arr[s].push_back(f);
    }

    fr(i,1,n+1) dp[i][0]=dp[i][1]=dp[i][2]=1;

    fr(i,0,k){
    	int x,c; cin>>x>>c;
    	dp[x][0]=dp[x][1]=dp[x][2]=0;
    	dp[x][--c]=1;
    }

    dfs(1,0);

    cout<<(dp[1][0]+dp[1][1]+dp[1][2])%MOD<<nL;
}

int main(){
	freopen("barnpainting.in","r",stdin);
	freopen("barnpainting.out","w",stdout);
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}