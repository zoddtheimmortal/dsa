/** 
 immortalzodd
 08.06.2024 11:49:00
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

#define A 26

ll n;
vector<string> names;
vector<vi> arr(A);

void solve(){
	cin>>n;
	names.resize(n); for(string&s:names) cin>>s;
	fr(i,1,n){
		string a=names[i-1],b=names[i];
		bool edge=false;
		fr(p,0,min(a.size(),b.size())){
			if(a[p]==b[p]) continue;
			edge=true;
			arr[a[p]-'a'].push_back(b[p]-'a');
			break;
		}
		if(!edge&&a.size()>b.size()){
			cout<<"Impossible"<<nL;
			return;
		}
	}

	string ans="";
	vi indeg(A,0);
	fr(i,0,A){
		for(int&x:arr[i]) indeg[x]++;
	}

	queue<int> qs;
	fr(i,0,A){
		if(indeg[i]==0) qs.push(i);
	}

	while(!qs.empty()){
		int v=qs.front();
		qs.pop();
		ans+=(v+'a');
		for(int&u:arr[v]){
			if(--indeg[u]==0) qs.push(u);
		}
	}
	cout<<((ans.size()<A)?"Impossible":ans)<<nL;
}

int main(){
    fast_io;
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}