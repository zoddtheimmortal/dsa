#include<iostream>
using namespace std;
void removeConsec(char str[]);
int main(){
	char str[101];cin>>str;
	removeConsec(str);
	cout<<str;	
}

void removeConsec(char str[]){
	if(str[0]=='\0') return;
	else if(str[0]==str[1])
}