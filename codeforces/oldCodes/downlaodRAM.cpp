#include<iostream>
using namespace std;
int maxRam(int k,int a[],int b[]);
void bubbleSort(int arr[],int index[],int n);
void arrangeArr(int b[],int newB[],int index[],int n);
int main(){
	int t; cin>>t;
	while(t--){
		int n,k; cin>>n>>k;
		int a[n],b[n];
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<n;i++) cin>>b[i];
		int index[n],newB[n];
		for(int i=0;i<n;i++) index[i]=i;
		bubbleSort(a,index,n);
		arrangeArr(b,newB,index,n);
		cout<<maxRam(k,a,newB)<<endl;
	}	
}

int maxRam(int k,int a[],int b[]){
	if(k<a[0]){
		return k;
	}
	else if(k+b[0]<a[1]){
		return k+b[0];
	}
	else{
		maxRam(k+b[0],a+1,b+1);
	}
}

void bubbleSort(int arr[],int index[],int n){
    int i,j;
    int swapped;
    for(i=0;i<n-1;i++){
       	swapped=0;
		for(j= 0; j<n-i-1; j++) {
            if (arr[j]>arr[j+1]) {
                swap(arr[j],arr[j+1]);
                swap(index[j],index[j+1]);
                swapped = 1;
            }
        }
        if (swapped==0)
            break;
    }
}

void arrangeArr(int b[],int newB[],int index[],int n){
	for(int i=0;i<n;i++){
		newB[i]=b[(index[i])];
	}
	return;
}