/** 
 immortalzodd
 30.07.2024 11:15:23
 maximumBuilding1
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

int n,m;

int histogram(vi& row){
	int n=row.size();
	int nle[n],ple[n];

	stack<int> ss;
	fr(i,0,n){
		while(!ss.empty()&&row[ss.top()]>row[i]) ss.pop();
		ple[i]=ss.empty()?-1:ss.top();
		ss.push(i);
	}

	while(!ss.empty()) ss.pop();
	rf(i,0,n-1){
		while(!ss.empty()&&row[ss.top()]>=row[i]) ss.pop();
		nle[i]=ss.empty()?n:ss.top();
		ss.push(i);
	}

	int ans=0;
	fr(i,0,n){
		ans=max(ans,row[i]*(nle[i]-ple[i]-1));
	}
	return ans;
}

void solve(){
    cin>>n>>m;
    vector<string> arr(n);
    for(string&s:arr) cin>>s;

    vi row(m,0);

	int ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j]=='*') row[j]=0;
			else row[j]++;
		}
		ans=max(ans,histogram(row));
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