#include<bits/stdc++.h>
using namespace std;
string roundMax(string str);
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t; cin>>t;
	while(t--){
		string str; cin>>str;
		str='0'+str;
		int n=str.size();
		for(int i=str.size()-1;i>=1;i--){
			if(str[i]-'0'>=5){
				str[i-1]++;
				n=i;
			}
		}
		for(int i=0;i<str.size();i++){
			if(str[i]=='0' && i==0) continue;
			if(i>=n){
				cout<<'0';
			}
			else cout<<str[i];
		}
		cout<<'\n';
	}	
}
