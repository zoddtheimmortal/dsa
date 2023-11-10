#include<iostream>
using namespace std;
void removeWub(char str[]);
void removeSpaces(char str[]);
void consecSpaces(char str[]);
int main(){
	char str[201]; cin>>str;
	removeWub(str);
	consecSpaces(str);
	removeSpaces(str);
	cout<<str<<'\n';	
}

void removeWub(char str[]){
	if(str[0]=='\0') return;
	else if(str[0]=='W' && str[1]=='U' && str[2]=='B'){
		str[0]=' ';
		str=str+1;
		int i=1;
		for(;str[i]!='\0';i++){
			str[i-1]=str[i];
		}
		str[i-1]='\0';
		i=1;
		for(;str[i]!='\0';i++){
			str[i-1]=str[i];
		}
		str[i-1]='\0';
		removeWub(str);
	}
	else{
		removeWub(str+1);
	}
}

void removeSpaces(char str[]){
	int i=0;
	for(;str[i]!='\0';i++);
	if(str[0]==' '){
		int j=1;
		for(;str[j]!='\0';j++){
			str[j-1]=str[j];
		}
		str[j-1]='\0';
	}
	if(str[i-1]==' ') str[i-1]='\0';\
	return;
}

void consecSpaces(char str[]){
	if(str[0]=='\0') return;
	else if(str[0]==' ' && str[1]==' '){
		int i=1;
		for(;str[i]!='\0';i++){
			str[i-1]=str[i];
		}
		str[i-1]='\0';
		consecSpaces(str);
	}
	else{
		consecSpaces(str+1);
	}
}