#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000005

int a[MAXN], qmax[MAXN], qmin[MAXN];

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    long long ans = 0;
    int head1 = 0, tail1 = -1, head2 = 0, tail2 = -1;
    for(int i = 0, j = 0; i < n; i++) {
        while(head1 <= tail1 && a[qmax[tail1]] < a[i]) tail1--;
        while(head2 <= tail2 && a[qmin[tail2]] > a[i]) tail2--;
        qmax[++tail1] = i;
        qmin[++tail2] = i;
        while(a[qmax[head1]] - a[qmin[head2]] > k) {
            j++;
            if(qmax[head1] < j) head1++;
            if(qmin[head2] < j) head2++;
        }
        ans += i - j + 1;
    }

    printf("%lld\n", ans);

    return 0;
}