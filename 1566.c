#include <stdio.h>

int main() {
    int NC;
    scanf("%d", &NC);

    while (NC--) {
        int N;
        scanf("%d", &N);

        int freq[231] = {0};

        for (int i = 0; i < N; i++) {
            int h;
            scanf("%d", &h);
            freq[h]++;
        }
        
        int first = 1;
        for (int h = 20; h <= 230; h++) {
            while (freq[h]--) {
                if (first) {
                    printf("%d", h);
                    first = 0;
                } else {
                    printf(" %d", h);
                }
            }
        }
        printf("\n");
    }

    return 0;
}
