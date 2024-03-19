#include<iostream>
using namespace std;
int dangerBall(char str[],int n);
int main(){
	char str[101]; cin>>str;	
	(dangerBall(str,0)==7)?(cout<<"YES"):(cout<<"NO");
}

int dangerBall(char str[],int n){
	if(str[0]=='\0') return n;
	else if(n>=6) return n+1;
	else if(str[0]==str[1]){
		dangerBall(str+1,n+1);
	}
	else{
		dangerBall(str+1,0);
	}
}