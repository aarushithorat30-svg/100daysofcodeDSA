#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int flag = 1;

    for (int i = 0; i <= (n - 2) / 2; i++) {
        if (2*i + 1 < n && arr[i] > arr[2*i + 1]) flag = 0;
        if (2*i + 2 < n && arr[i] > arr[2*i + 2]) flag = 0;
    }

    if (flag) printf("YES");
    else printf("NO");

    return 0;
}