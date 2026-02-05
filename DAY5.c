#include <stdio.h>

int main() {
    int p, q;
    int log1[200], log2[200], merged[400];
    int i = 0, j = 0, k = 0;

    scanf("%d", &p);
    for (i = 0; i < p; i++) {
        scanf("%d", &log1[i]);
    }

    scanf("%d", &q);
    for (i = 0; i < q; i++) {
        scanf("%d", &log2[i]);
    }

    i = 0;
    j = 0;

    while (i < p && j < q) {
        if (log1[i] <= log2[j]) {
            merged[k] = log1[i];
            i++;
        } else {
            merged[k] = log2[j];
            j++;
        }
        k++;
    }

    while (i < p) {
        merged[k] = log1[i];
        i++;
        k++;
    }

    while (j < q) {
        merged[k] = log2[j];
        j++;
        k++;
    }

    for (i = 0; i < p + q; i++) {
        printf("%d ", merged[i]);
    }

    return 0;
}
