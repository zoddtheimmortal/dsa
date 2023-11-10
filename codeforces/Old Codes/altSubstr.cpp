#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using pd = pair<ld, ld>;
using vi = vector<int>;
using vl = vector<ll>;
using vd = vector<ld>;
using vpi = vector<pi>;
using vpl = vector<pl>;
using vpd = vector<pd>;
using vvi = vector<vi>;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define fr(i, a, b) for (int i = a; i < (b); ++i)
#define rf(i, a, b) for (int i = b; i >=(a); i--)
#define nL "\n"

int getType(string str);

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin>>t;
	while(t--){
		string str; cin>>str;
		int type=getType(str);
		string ban="()";
		if(str.size()!=2 || !(str[0]=='('&&str[1]==')')){
			cout<<"YES"<<nL;
			if(type==1){
				fr(i,0,(2*str.size())){
					if(i%2==0) cout<<"(";
					else cout<<")";
				}
			}
			else if(type==2){
				fr(i,0,(str.size())) cout<<"(";
				fr(i,0,(str.size())) cout<<")";
			}
			cout<<nL;
		}
		else cout<<"NO\n";
	}
}

int getType(string str){
	fr(i,1,(str.size())){
		if(str[i]==str[i-1]) return 1;
	}
	return 2;
}

