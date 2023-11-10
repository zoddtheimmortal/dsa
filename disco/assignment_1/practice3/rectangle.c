#include<stdio.h>

struct point{
    int x,y;
};

int main(){
    int n; scanf("%d",&n);   
    struct point arr[n]; for(int i=0;i<n;i++) scanf("%d %d",&arr[i].x,&arr[i].y);

    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i].x!=arr[j].x && arr[i].y!=arr[j].y){
                int flag=0;
                for(int k=0;k<n;k++){
                    if(arr[k].x==arr[i].x && arr[k].y==arr[j].y) flag++;
                    if(arr[k].x==arr[j].x && arr[k].y==arr[i].y) flag++;
                }
                if(flag==2) ans++;
            }
        }
    }

    printf("%d\n",ans/4);
}