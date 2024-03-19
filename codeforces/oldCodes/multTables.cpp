#include<iostream>
using namespace std;
int main(){
	int n,x; cin>>n>>x;
	int count=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i*j==x){
				count++;
			}
		}
	}
	cout<<count<<"\n";
}