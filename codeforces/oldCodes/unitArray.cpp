#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--){
		int juan=0,mjuan=0,n; cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++){
			cin>>a[i];
			if(a[i]==1) juan++;
			else mjuan++;
		}
		int moves=0;
		while(!(juan>=mjuan && mjuan%2==0)){
			mjuan--; juan++; moves++;
		}
		cout<<moves<<endl;

	}	
}