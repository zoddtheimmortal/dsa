#include<iostream>
using namespace std;
void removeVowels(char str[]);
int main(){
	char str[205]; cin>>str;
	for(int i=0;str[i]!='\0';i++){
		if(65<=str[i] && str[i]<=90) str[i]=str[i]+32;
	}
	removeVowels(str);
	cout<<str<<endl;
}

void removeVowels(char str[]){
	if(str[0]=='\0') return;
	else if(str[0]=='a' || str[0]=='e' || str[0]=='i' || str[0]=='o' ||str[0]=='u' || str[0]=='y'){
		int i=1;
		for(;str[i]!='\0';i++) str[i-1]=str[i];
		str[i-1]='\0';
		removeVowels(str);
	}
	else{
		int i=0,j;
		for(;str[i]!='\0';i++);
		j=i-1;
		for(;j>=0;j--){
			str[j+1]=str[j];
		}
		str[0]='.';
		str[i+1]='\0';
		removeVowels(str+2);
	}
}