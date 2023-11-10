#include<stdio.h>
#define N 250
#define ll long long

int subset[N]={0},size=0;
void pushback(int data){
    subset[size++]=data;
}

void popback(){
    subset[--size]=0;
}

void search(int k,int arr[],int n,int target,int flag[]){
    if(flag[0]==1) return;
    if(k==n){
        ll sum=0;
        for(int i=0;i<n;i++) sum+=subset[i];
        if(sum==target){
            int len=0;
            for(int i=0;i<n;i++){
                if(subset[i]!=0) len++;
            }
            printf("%d\n",len);
            for(int i=0;i<n;i++){
                if(subset[i]!=0) printf("%d ",subset[i]);
            }
            printf("\n");
            flag[0]=1;
        }
    }
    else{
        pushback(arr[k]);
        search(k+1,arr,n,target,flag);
        popback();
        search(k+1,arr,n,target,flag);
    }
}

int main(){
    int n,target; scanf("%d %d",&n,&target);
    int arr[n]; for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    int flag[1]={0};
    search(0,arr,n,target,flag);
}