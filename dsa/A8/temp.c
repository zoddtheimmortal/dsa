#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    char *s = (char *)malloc((n + 1) * sizeof(char));
    scanf("%s", s);

    int top = 0;
    for (int i = 1; i < n; i++) {
        while (top >= 0 && s[i] < s[top] && k > 0) {
            s[top] = '0';
            top--;
            k--;
        }
        s[++top] = s[i];
    }

    while (k--) {
        s[top--] = '0';
    }

    int start = 0;
    while (s[start] == '0') {
        start++;
    }

    if (start <= top) {
        printf("%s\n", s + start);
    } else {
        printf("0\n");
    }

    free(s);
    return 0;
}