#include<iostream>
using namespace std;
int openDoors(int arr[],int key);
int main(){
	int t; cin>>t;
	while(t--){
		int x; cin>>x;
		int keyRow[3]; for(int i=0;i<3;i++) cin>>keyRow[i];
		if(openDoors(keyRow,x)) cout<<"YES\n";
		else cout<<"NO\n";
	}	
}

int openDoors(int arr[],int key){
	int search=1;
	while(search<3){
		if(arr[key-1]==0){
			return 0;
		}
		else{
			search++;
			key=arr[key-1];
		}
	}
	return 1;
}