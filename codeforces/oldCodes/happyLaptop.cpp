#include<bits/stdc++.h>
using namespace std;
struct laptop
{
	int price,qual;
};
bool compare(laptop l1,laptop l2);
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin>>n;
	struct laptop lap[n];
	for(int i=0;i<n;i++){
		cin>>lap[i].price>>lap[i].qual;
	}
	sort(lap,lap+n,compare);
	for(int i=1;i<n;i++){
		if(lap[i-1].qual>lap[i].qual && lap[i-1].price<lap[i].price){
			cout<<"Happy Alex"<<endl;
			return 0;
		}
	}
	cout<<"Poor Alex"<<endl;
}

bool compare(laptop l1,laptop l2){
	return l1.price<l2.price;
}