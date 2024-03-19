#include<iostream>
#include<vector>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		string str; cin>>str;
		int n=str.size();
		std::vector<bool> a(n+1); a[0]=true;
		for(int i=0;i<n;i++){
			a[i+1]=a[i]&&(str[i]=='1'||str[i]=='?');
		}
		std::vector<bool> b(n+1); b[n]=true;
		for(int i=n-1;i>=0;i--){
			b[i]=b[i+1]&&(str[i]=='0'||str[i]=='?');
		}
		int results=0;
		for(int i=0;i<n;i++){
			if(a[i]&&b[i]) results++;
		}
		cout<<results<<endl;
	}
}