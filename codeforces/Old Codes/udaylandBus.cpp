#include<iostream>
using namespace std;
int checkSeats(char str[]);
int main(){
	int t,flag=0; cin>>t;
	char holder[t][10];
	for(int i=0;i<t;i++){
		cin>>holder[i];
		if(flag==0){
			flag=checkSeats(holder[i]);
		}
	}
	if(flag==1){
		cout<<"YES"<<endl;
		for(int i=0;i<t;i++){
			cout<<holder[i]<<endl;
		}
	}
	else{
		cout<<"NO"<<endl;
	}
}

int checkSeats(char str[]){
	if(str[0]=='\0') return 0;
	else if(str[0]=='O' && str[1]=='O'){
		str[0]='+'; str[1]='+';
		return 1;
	}
	else{
		checkSeats(str+1);
	}
}