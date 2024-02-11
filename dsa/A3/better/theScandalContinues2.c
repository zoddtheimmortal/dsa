#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

int countSetBits(long long n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

int max_satisfied_clients(int n, int k, long long a[]) {
    long long maxSatisfiedClients = 0;
    long long currentSatisfiedClients = 0;
    int deque[MAXN];
    int front = 0, back = -1;

    for (int i = 0; i < n; i++) {
        currentSatisfiedClients |= a[i];

        while (front <= back && (currentSatisfiedClients | a[deque[back]]) == currentSatisfiedClients) {
            back--;
        }
        deque[++back] = i;

        if (i >= k && deque[front] == i - k) {
            front++;
            currentSatisfiedClients = 0;
            for (int j = front; j <= back; j++) {
                currentSatisfiedClients |= a[deque[j]];
            }
        }

        maxSatisfiedClients = max(maxSatisfiedClients, currentSatisfiedClients);
    }

    return countSetBits(maxSatisfiedClients);
}

int main(){
	int n,k; scanf("%d %d",&n,&k);
	ll* arr=(ll*) malloc(sizeof(ll)*n);
	for(int i=0;i<n;i++) scanf("%lld",&arr[i]);
	int ans=max_satisfied_clients(n,k,arr);

	printf("%d\n",ans);

	free(arr);
}