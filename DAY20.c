#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long prefix = 0;
    long long count = 0;

    long long freq[200001] = {0};
    int offset = 100000;

    freq[offset] = 1;

    for(int i = 0; i < n; i++) {
        prefix += arr[i];

        if(freq[prefix + offset] > 0) {
            count += freq[prefix + offset];
        }

        freq[prefix + offset]++;
    }

    printf("%lld\n", count);

    return 0;
}
