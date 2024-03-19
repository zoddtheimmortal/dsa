#include<iostream>
using namespace std;
int padReverse(int n,char str[]);
int main(){
	int t; cin>>t;	
	while(t--){
		int n; cin>>n;
		int arr[n]; for(int i=0;i<n;i++) cin>>arr[i];
		for(int i=0;i<n;i++){
			int k; cin>>k;
			char str[50]; cin>>str;
			arr[i]=padReverse(arr[i],str);
			cout<<arr[i]<<' ';
		}
		// for(int i=0;i<n;i++) cout<<arr[i]<<' ';
		cout<<endl;
	}
}

int padReverse(int n,char str[]){
	if(str[0]=='\0'){
		return n;
	}
	else if(str[0]=='U' && n==0){
		// cout<<9<<' ';
		padReverse(9,str+1);
	}
	else if(str[0]=='D' && n==9){
		// cout<<0<<' ';
		padReverse(0,str+1);
	}
	else if(str[0]=='D'){
		// cout<<n+1<<' ';
		padReverse(n+1,str+1);
	}
	else if(str[0]=='U'){
		// cout<<n-1<<' ';
		padReverse(n-1,str+1);
	}
}