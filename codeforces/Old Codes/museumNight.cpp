#include<iostream>
#define min(a,b) (a>b)?b:a
#define abs(m) (m>=0)?m:(-m)
int countRotations(char str[],char x,int n);
using namespace std;
int main(){
	char str[101]; cin>>str;
	int x=countRotations(str,'a',0);	
	cout<<x;
	return 0;
}

int countRotations(char str[],char x,int n){
	if(str[0]=='\0') return n;
	else{
		int k=abs((str[0]-x));
		int y=min(k,(26-k));
		return countRotations(str+1,str[0],n+y);
	}
}