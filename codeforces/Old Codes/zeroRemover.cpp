#include<iostream>
using namespace std;
int removeZero(char str[],int c);
int zCounter(char str[]);
int main(){
	int t; cin>>t;
	while(t--){
		char str[101]; cin>>str;
		int zero=removeZero(str,0);
		cout<<zero<<endl;
	}
}

int removeZero(char str[],int c){
	if(str[0]=='\0') return c;
	else if(str[0]=='1' && str[1]=='0'){
		int x=zCounter(str+1);
		removeZero(str+1,c+x);
	}
	else{
		removeZero(str+1,c);
	}
}

int zCounter(char str[]){
	int x=0;
	for(;;x++){
		if(str[x]=='1'){
			return x;
		}
		else if(str[x]=='\0'){
			return 0;
		}
	}
}

