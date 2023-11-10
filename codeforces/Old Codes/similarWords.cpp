#include<iostream>
using namespace std;
#define abs(a) a>0?a:-a 
int compareStr(char s1[],char s2[]);
int main(){
	int t; cin>>t;
	while(t--){
		int n,m; cin>>n>>m;
		char arr[n][m];
		for(int i=0;i<n;i++){
			cin>>arr[i];
			arr[i][m]='\0';
		}
		int x=m*27;
		for(int i=0;i<n-1;i++){
			for(int j=i+1;j<n;j++){
				cout<<arr[i]<<" "<<arr[j]<<endl;
				int c=compareStr(arr[i],arr[j]);
				if(c<x) x=c;
				cout<<x<<endl;
			}
		}
		cout<<"ans";
		cout<<x<<endl;
	}
}

int compareStr(char s1[],char s2[]){
	int k=0;
	for(int i=0;s2[i]!='\0';i++){
		k+=abs((s1[i]-s2[i]));
	}
	cout<<"**"<<endl;
	return k;
}