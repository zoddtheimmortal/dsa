#include<iostream>
using namespace std;
void birdLand(char x[],char y[],int n);
int main(){
	char x[101],y[101]; cin>>x>>y;
	int i=0,j=0;
	for(;x[i]!='\0';i++);
	for(;y[j]!='\0';j++);
	if(i==j){
		birdLand(x,y,i);
	}
	else{
		cout<<"NO";
	}
}

void birdLand(char x[],char y[],int n){
	for(int i=0;i<n;i++){
		if(x[i]!=y[n-i-1]){
			cout<<"NO";
			return;
		}
	}
	cout<<"YES"; return;
}