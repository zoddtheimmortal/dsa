/** 
 immortalzodd
 09.06.2024 16:33:18
 quantumSuperposition
**/
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using vb = vector<bool>;

#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define nL "\n"
#define fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr)

ll p,q,r,s,Q;
vector<vi> arr,brr;

vector<vi> fill_dp(vector<vi>& arr,int p){
	vi indeg(p,0);
    fr(i,0,p){
    	for(int&x:arr[i]) indeg[x]++;
    }
	
	queue<int> qs;
	fr(i,0,p) if(indeg[i]==0) qs.push(i);

	vector<vi> dp(p,vi(p,0));
	dp[0][0]=1;
	while(!qs.empty()){
		int v=qs.front();
		qs.pop();
		for(int&u:arr[v]){
			fr(i,0,p){
				dp[u][i]|=dp[v][i-1];
			}
			if(--indeg[u]==0) qs.push(u);
		}
	}

	fr(i,0,p){
		fr(j,0,p) cout<<dp[i][j]<<" ";
		cout<<nL;
	}
	return dp;
}

void solve(){
    cin>>p>>q>>r>>s;
    arr.resize(p); brr.resize(q);
    fr(i,0,r){
    	ll f,s; cin>>f>>s;
    	arr[--f].push_back(--s);
    }
    fr(i,0,s){
    	ll f,s; cin>>f>>s;
    	brr[--f].push_back(--s);
    }
    vector<vi> dpx=fill_dp(arr,p);
    vector<vi> dpy=fill_dp(brr,q);

    bitset<MAX_Q+1> ans;
    fr(i,0,MAX_N+1){
    	if(dpx[p][0])
    }

    cin>>Q;
    while(Q--){
    	int x; cin>>x;
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