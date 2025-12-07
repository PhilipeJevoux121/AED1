#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char s[200000];
    char *v[200000];
    int q = 0;
  
    while (scanf("%s", s) != EOF) {
        int tem = 0;
        for (int i = 0; i < q; i++) {
            if (strcmp(v[i], s) == 0) {
                tem = 1;
                break;
            }
        }
        if (!tem) {
            v[q] = malloc(strlen(s) + 1);
            strcpy(v[q], s);
            q++;
        }
    }
    printf("%d\n", q);
    return 0;
}
