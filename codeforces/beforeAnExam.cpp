/** 
 immortalzodd
 01.06.2024 08:41:22
 beforeAnExam
**/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;
using vl = vector<ll>;

#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define nL "\n"
#define f first
#define s second
#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)

ll n,x;
vector<pii> arr;

void solve(){
	cin>>n>>x;
	arr.resize(n); for(pii&p:arr) cin>>p.f>>p.s;
	vector<vi> dp(n+1,vi(x+1,0)),track(n+1,vi(x+1,-1));
	dp[0][0]=1;
	fr(i,1,n+1){
		fr(j,0,x+1){
			fr(k,arr[i-1].f,arr[i-1].s+1){
				if(j-k>=0&&dp[i-1][j-k]==1){
					dp[i][j]=1;
					track[i][j]=k;
				}
			}
		}
	}
	vi arr;
	int i=n,j=x;
	while(i>=1&&j>=0){
		arr.push_back(track[i][j]);
		j-=track[i][j];
		i--;
	}
	if(!dp[n][x]) cout<<"NO"<<nL;
	else{
		cout<<"YES"<<nL;
		reverse(all(arr));
		for(int&x:arr) cout<<x<<" ";
		cout<<nL;
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