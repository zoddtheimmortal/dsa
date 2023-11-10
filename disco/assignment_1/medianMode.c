#include<stdio.h>
#define ll long long

void merge(int arr[],int l,int m,int r){
    int i,j,k;
    int left[m-l+1],right[r-m];

    for(i=0;i<m-l+1;i++) left[i]=arr[l+i];
    for(j=0;j<r-m;j++)  right[j]=arr[m+1+j];

    i=0,j=0,k=l;

    while(i<(m-l+1) && j<r-m){
        if(left[i]<=right[j]){
            arr[k++]=left[i++];
        }
        else{
            arr[k++]=right[j++];
        }
    }

    while(i<(m-l+1)){
        arr[k++]=left[i++];
    }

    while(j<r-m){
        arr[k++]=right[j++];
    }
}

void mergeSort(int arr[],int l,int r){
    if(l<r){
        int m=l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main(){
    int n; scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        int x; scanf("%d",&x);
        arr[i]=x;
    }

    mergeSort(arr,0,n-1);

    int median=arr[n/2];
    int temp=1,tempMax=1,mode=-1;
    for(int i=n-1;i>0;i--){
        if(arr[i-1]==arr[i]) temp++;
        else{
            temp=1;
        }

        if(temp>=tempMax){
            tempMax=temp;
            mode=arr[i];
        }
    }
    printf("%d %d",median,mode);
}