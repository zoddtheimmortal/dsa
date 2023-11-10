#include<iostream>
using namespace std;
int maxRam(int k,int a[],int b[],int n);
void sortAndMap(int arr[],int index[],int n);
int main(){
	int t; cin>>t;
	while(t--){
		int n,k; cin>>n>>k;
		int a[n],b[n];
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<n;i++) cin>>b[i];
		sortAndMap(a,b,n);
		cout<<maxRam(k,a,b,n)<<endl;
	}	
}

int maxRam(int k,int a[],int b[],int n){
	if(n==0){
		return k;
	}
	else if(k<a[0]){
		return k;
	}
	else if(k+b[0]<a[1] && n>=1){
		return k+b[0];
	}
	else{
		maxRam(k+b[0],a+1,b+1,n-1);
	}
}

void sortAndMap(int arr[],int b[],int n){
    int i,j;
    int swapped;
    for(i=0;i<n-1;i++){
       	swapped=0;
		for(j= 0; j<n-i-1; j++) {
            if (arr[j]>arr[j+1]) {
                swap(arr[j],arr[j+1]);
                swap(b[j],b[j+1]);
                swapped = 1;
            }
        }
        if (swapped==0)
            break;
    }
}