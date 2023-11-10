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
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define nL "\n"
 
int main(){
	// ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin>>t;
	while(t--){
		int n,k,x; cin>>n>>k>>x;
		if(x!=1){
			cout<<"YES\n"<<n<<nL;
			rep(i,0,n) cout<<1<<" ";
			cout<<nL;
		}
		else if(k==1||(k==2&&n%2!=0)){
			cout<<"NO\n";
		}
		else{
			cout<<"YES\n"<<n/2<<nL;
			int x=(n%2==1)?3:2;
			for(int i=0;i<(n/2);i++){
				cout<<x<<" ";
				if(x==3) x--;
			}
			cout<<endl;
		}
	}
}