#include <stdio.h>

int main() {
    int V = 0;
    int T = 0;
    while (scanf("%d %d", &V, &T) != EOF) {
        printf("%d\n", V * 2 * T);
    }

    return 0;
}
