#include<iostream>
using namespace std;
void removeWub(char str[]);
void removeFSpace(char str[]);
void removeCSpace(char str[]);
int main(){
	char str[201],newstr[201]; cin>>str;
	removeWub(str); 
	removeFSpace(str);
	removeCSpace(str);
	cout<<str;
}

void removeWub(char str[]){
	if(str[0]=='\0') return;
	else if(str[0]=='W' && str[1]=='U' && str[2]=='B'){
		str[0]=' ';
		removeWub(str+1);
	}
	else if(str[0]=='U' && str[1]=='B'){
		int k=1;
		for(int j=1;str[j]!='\0';j++) str[j-1]=str[j];
		for(;str[k]!='\0';k++) str[k-1]=str[k];
		str[k-2]='\0';
		removeWub(str);
	}
	else removeWub(str+1);
}

void removeFSpace(char str[]){
	if(str[0]=='\0') return;
	else if(str[0]==' '){
		int k=1;
		for(;str[k]!='\0';k++){
			str[k-1]=str[k];
		}
		str[k-1]='\0';
		removeFSpace(str);
	}
	else return;
}

void removeCSpace(char str[]){
	if(str[0]=='\0') return;
	else if(str[0]==' ' && str[1]==' '){
		int k=1;
		for(;str[k]!='\0';k++){
			str[k-1]=str[k];
		}
		str[k-1]='\0';
		removeCSpace(str);
	}
	else removeCSpace(str+1);
}