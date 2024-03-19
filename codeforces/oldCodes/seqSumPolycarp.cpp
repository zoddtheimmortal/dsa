#include<iostream>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		int* b=new int[7]; for(int i=0;i<7;i++) cin>>b[i];
		if(b[5]-b[1]==b[4]-b[0]){
			cout<<b[0]<<" "<<b[1]<<" "<<b[5]-b[1]<<endl;
		}
		delete[] b;
	}
}