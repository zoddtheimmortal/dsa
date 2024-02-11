#include <stdio.h>
#define MAXN 100005
#define LL long long

LL a[MAXN], prefix[MAXN], suffix[MAXN];

LL max(LL a, LL b) {
    return a > b ? a : b;
}

int main() {
    int n, k, i;
    scanf("%d %d", &n, &k);
    for(i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    for(i = 1; i <= n; i++) {
        prefix[i] = prefix[i-1] | a[i];
    }
    for(i = n; i >= 1; i--) {
        suffix[i] = suffix[i+1] | a[i];
    }
    LL maxSatisfaction = prefix[k];
    for(i = k; i <= n; i++) {
        maxSatisfaction = max(maxSatisfaction, prefix[i-k] | a[i] | suffix[i+1]);
    }
    printf("%lld\n", maxSatisfaction);
    return 0;
}