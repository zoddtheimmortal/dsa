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

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t; cin>>t;
	while(t--){
		int r,c; cin>>r>>c;
		char arr[r][c];
		fr(i,0,r){
			fr(j,0,c){
				cin>>arr[i][j];
			}
		}
		int count=0; string v="vika";
		fr(j,0,c){
			fr(i,0,r){
				if(count==0 && arr[i][j]=='v'){
					count++;
					break;
				}
				if(count==1 && arr[i][j]=='i'){
					count++;
					break;
				}
				if(count==2 && arr[i][j]=='k'){
					count++;
					break;
				}
				if(count==3 && arr[i][j]=='a'){
					count++;
					break;
				}
			}
		}
		if(count==4) cout<<"YES\n";
		else cout<<"NO\n";
	}
}

