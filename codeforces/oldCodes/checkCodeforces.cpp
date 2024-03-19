#include<iostream>
using namespace std;
int main(){
	int t; char x; cin>>t;
	while(t--){
		//codefrs
		cin>>x;
		if(x=='c'||x=='o'||x=='d'||x=='e'||x=='f'||x=='r'||x=='s'){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}	
}