#include<iostream>
using namespace std;
int main(){
	int t; cin>>t;
	while(t--){
		char x,op[9];
		int k=0;
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				cin>>x;
				if(x!='.'){
					op[k++]=x;
				}
			}
		}
		op[k]='\0';
		cout<<op<<endl;
	}	
}