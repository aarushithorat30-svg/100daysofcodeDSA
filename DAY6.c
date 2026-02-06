#include <stdio.h>

int main() {
    int n;
    int arr[200];
    int i, k;

    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (n == 0) {
        return 0;
    }

    k = 1;

    for (i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            arr[k] = arr[i];
            k++;
        }
    }

    for (i = 0; i < k; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
