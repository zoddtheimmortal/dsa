#include<iostream>
using namespace std;
void swapElements(int arr[],int n,int index,int dir);
int main(){
	int n; cin>>n;
	int arr[n]; for(int i=0;i<n;i++) cin>>arr[i];
	int max=arr[0],min=arr[0],keyMax=0,keyMin=0; //first occ of max and last of min
	for(int i=0;i<n;i++){
		if(arr[i]>max){
			max=arr[i]; keyMax=i;
		}
	}
	for(int i=n;i>=0;i--){
		if(arr[i]<min){
			min=arr[i]; keyMin=i;
		}
	}
	if(keyMax>n-keyMin){
		int x=
	}
}

void swapElements(int arr[],int n,int index,int dir){
	if(dir==0){ //max height
		for(int i=index;i>0;i--){
			cout<<arr[i-1]<<" "<<i-1<<arr[i]<<" "<<i<<endl;
			int temp=arr[i-1];
			arr[i-1]=arr[i];
			arr[i]=temp;
		}
	}
	else if(dir==1){ //min height
		for(int i=index+1;i<n;i++){
			int temp=arr[i-1];
			arr[i-1]=arr[i];
			arr[i]=temp;
		}
	}

}