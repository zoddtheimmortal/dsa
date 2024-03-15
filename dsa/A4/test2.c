#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

char* lcm_of_strings(char* a, char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    int gcd_ab = gcd(len_a, len_b);

    char pattern[1000000];
    strncpy(pattern, a, gcd_ab);
    pattern[gcd_ab] = '\0';

    for (int i = 0; i < len_a; i++) {
        if (a[i] != pattern[i % gcd_ab]) {
            return "-1";
        }
    }
    for (int i = 0; i < len_b; i++) {
        if (b[i] != pattern[i % gcd_ab]) {
            return "-1";
        }
    }

    int lcm_len = len_a * len_b / gcd_ab;
    char* lcm = (char*)malloc((lcm_len + 1) * sizeof(char));
    for (int i = 0; i < lcm_len; i++) {
        lcm[i] = pattern[i % gcd_ab];
    }
    lcm[lcm_len] = '\0';

    return lcm;
}

int main() {
    char a[1000000];
    char b[1000000];
    scanf("%s", a);
    scanf("%s", b);
    printf("%s\n", lcm_of_strings(a, b));
    return 0;
}