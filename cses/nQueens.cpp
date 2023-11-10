#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<ld>;

#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define fr(i, a, b) for (ll i = a; i < (b); ++i)
#define rf(i, a, b) for (ll i = b; i >=(a); i--)
#define rep(i,arr) for(auto i:arr)
#define nL "\n"

void search(int y,ll* count,vi &col,vi &diag1,vi &diag2,vector<pair<int,int>> res);

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	vector<pair<int,int>> res;
	char temp;
	fr(i,0,8){
		fr(j,0,8){
			cin>>temp;
			if(temp=='*'){
				res.pb(make_pair(i,j));
			}
		}
	}
	vi col(8),diag1(8),diag2(8);
	ll count=0;
	ll* p=&count;
	search(0,p,col,diag1,diag2,res);
	cout<<count<<nL;

}

void search(int y,ll* count,vi &col,vi &diag1,vi &diag2,vector<pair<int,int>> res){
	int n=8;
	if(y==n){
		(*count)++;
		return;
	}
	fr(x,0,n){
		if(col[x]||diag1[x+y]||diag2[x+y]) continue;

		// pair<int,int> temp=make_pair(x,y);
		// if(find(all(res),temp)!=res.end()) continue;

		col[x]=diag1[x+y]=diag2[x-y+n-1]=1;
		search(y+1,count,col,diag1,diag2,res);
		col[x]=diag1[x+y]=diag2[x-y+n-1]=0;
	}
}