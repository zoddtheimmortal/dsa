#include<stdio.h>

int main(){
    int n; scanf("%d",&n);
    int arr[n][2]; 
    for(int i=0;i<n;i++){
        scanf("%d %d",&arr[i][0],&arr[i][1]);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][0]!=arr[j][0] && arr[i][1]!=arr[j][1]){
                int flag=0;
                for(int k=0;k<n;k++){
                    if(arr[k][0]==arr[i][0] && arr[k][1]==arr[j][1]) flag++;
                    if(arr[k][0]==arr[j][0] && arr[k][1]==arr[i][1]) flag++;
                }
                if(flag==2) ans++;
            }
        }
    }
    printf("%d\n",ans/4);
}