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
		int n; cin>>n;
		vi arr(n); fr(i,0,n) cin>>arr[i];
		int winPosn=n,winNum=INT_MAX;
		fr(i,1,n){
			if(arr[i-1]<arr[i]){
				winPosn=i-1;
				winNum=arr[i-1];
				break;
			}
		}
		int temp=INT_MAX,count=0;
		fr(i,winPosn+1,n){
			if(arr[i]>winNum && arr[i]<temp){
				temp=arr[i];
				count++;
			}
		}
		cout<<count<<nL;
	}
}

