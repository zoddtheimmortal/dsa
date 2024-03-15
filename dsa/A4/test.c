#include <stdio.h>
#include <string.h>

char* lcm_of_strings(char* a, char* b) {
    int len_a = strlen(a);
    int len_b = strlen(b);
    int i;
    for (i = 0; i < len_a && i < len_b; i++) {
        if (a[i] != b[i]) {
            break;
        }
    }
    char prefix[1000000];
    strncpy(prefix, a, i);
    prefix[i] = '\0';
    for (int j = 0; j < len_a; j++) {
        if (a[j] != prefix[j % i]) {
            return "-1";
        }
    }
    for (int j = 0; j < len_b; j++) {
        if (b[j] != prefix[j % i]) {
            return "-1";
        }
    }
    return len_a > len_b ? a : b;
}

int main() {
    char a[1000000];
    char b[1000000];
    scanf("%s", a);
    scanf("%s", b);
    printf("%s\n", lcm_of_strings(a, b));
    return 0;
}