#include<iostream>
using namespace std;
void lowerCase(char str[]);
void compareStr(char str[]);
int main(){
	int t; cin>>t;
	while(t--){
		char str[10]; cin>>str;
		lowerCase(str);
		compareStr(str);
	}	
}

void lowerCase(char str[]){
	if(str[0]=='\0') return;
	else if(str[0]>=65 && str[0]<=90){
		str[0]+=32;
		lowerCase(str+1);
	}
	else{
		lowerCase(str+1);
	}
}

void compareStr(char str[]){
	if(str[0]=='y' && str[1]=='e' && str[2]=='s'){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}
}