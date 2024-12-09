/** 
 immortalzodd
 17.08.2024 09:55:29
 foxAndNames
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

void solve(){
    ll n; cin>>n;
    vector<string> words(n);
    for(string&s:words) cin>>s;

    vector<vi> arr(26);
	fr(k,1,n){
		string a=words[k-1];
		string b=words[k];

		bool edge=false;
		fr(i,0,min(a.size(),b.size())){
			if(a[i]!=b[i]){
				arr[a[i]-'a'].push_back(b[i]-'a');
				edge|=true;
				break;
			}
		}
		if(!edge&&a.size()>b.size()){
			cout<<"Impossible"<<nL;
			return;
		}
	}

	vi indeg(26,0);
	fr(i,0,26){
		for(int&x:arr[i]) indeg[x]++;
	}

	queue<int> qs;
	fr(i,0,26) if(indeg[i]==0) qs.push(i);

	string ans="";
	while(!qs.empty()){
		int v=qs.front();
		qs.pop();
		ans+=(v+'a');

		for(int&u:arr[v]){
			if(--indeg[u]==0) qs.push(u);
		}
	}

	cout<<(ans.size()!=26?"Impossible":ans)<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}