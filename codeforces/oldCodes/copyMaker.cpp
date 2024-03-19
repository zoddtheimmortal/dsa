//stupid fucking question
#include<iostream>
using namespace std;
int notUnique(int arr[],int n,int k);
void mergeSort(int arr[],int si,int ei);
void merge(int array[], int const left, int const mid,int const right);
int main(){
	int t; cin>>t;
	while(t--){
		int n; cin>>n;
		int arr[n]; for(int i=0;i<n;i++) cin>>arr[i];
		mergeSort(arr,0,n-1);
		cout<<n-(notUnique(arr,n,0))<<endl;
	}	
}

void mergeSort(int arr[],int si,int ei){
	if(si>=ei) return;
	int mid=si+((ei-si)/2);
	mergeSort(arr,si,mid);
	mergeSort(arr,mid+1,ei);
	merge(arr,si,mid,ei);
}

void merge(int array[], int const left, int const mid,int const right){
    int const n1 = mid - left + 1;
    int const n2 = right - mid;
    auto *L = new int[n1],*R = new int[n2];
    for (auto i = 0; i < n1; i++){
        L[i] = array[left + i];
    }
    for (auto j = 0; j < n2; j++){
        R[j] = array[mid + 1 + j];
    }
    auto i = 0, j = 0;
    int k = left;
    while (i < n1&& j < n2) {
        if (L[i]<= R[j]) {
            array[k]= L[i];
            i++;
        }
        else {
            array[k]= R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        array[k]= L[i];
        i++;k++;
    }
    while (j < n2) {
        array[k]= R[j];
        j++;k++;
    }
    delete[] L;delete[] R;
}

int notUnique(int arr[],int n,int m){
	if(n==0) return m;
	else if(arr[0]==arr[1] && n>1){
		notUnique(arr+1,n-1,m+1);
	}
	else{
		notUnique(arr+1,n-1,m);
	}
}