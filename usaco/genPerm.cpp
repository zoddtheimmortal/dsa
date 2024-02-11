/** 
 immortalZodd
 07.02.2024 23:25:19
 genPerm
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

int N=1e9+7;

vi arr(N,0);
vector<vi> perms;
vector<bool> chosen(N,false);
vi permutation;

void gen(){
	if(permutation.size()==arr.size()){
		perms.push_back(permutation);
		return;
	}
	fr(i,0,arr.size()){
		if(chosen[i]) continue;
		chosen[i]=true;
		permutation.push_back(arr[i]);
		gen();
		chosen[i]=false;
		permutation.pop_back();
	}
}


void solve(){
    ll n; cin>>n;
    arr.resize(n);
    chosen.resize(n);
    for(auto &x:arr) cin>>x;

    gen();

	for(auto &a:perms){
		for(auto &x:a) cout<<x<<" ";
		cout<<nL;
	}
}

int main(){
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
  
    ll t=1;
    // cin>>t;

    while(t--){
        solve();
    }
}