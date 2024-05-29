#include <stdio.h>
#define MAXN 1000005

int a[MAXN];
int maxDeque[MAXN], minDeque[MAXN];

int main() {
    int n, k;
    long long count = 0;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    int frontMax = 0, backMax = -1;
    int frontMin = 0, backMin = -1;
    int j = 0;
    for(int i = 0; i < n; i++) {
        while(frontMax <= backMax && a[i] > a[maxDeque[backMax]]) backMax--;
        while(frontMin <= backMin && a[i] < a[minDeque[backMin]]) backMin--;
        maxDeque[++backMax] = i;
        minDeque[++backMin] = i;
        while(a[maxDeque[frontMax]] - a[minDeque[frontMin]] > k) {
            if(maxDeque[frontMax] < minDeque[frontMin]) j = maxDeque[frontMax++] + 1;
            else j = minDeque[frontMin++] + 1;
        }
        count += i - j + 1;
    }
    printf("%lld\n", count);
    return 0;
}