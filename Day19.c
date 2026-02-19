#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    qsort(arr, n, sizeof(int), compare);

    int left = 0, right = n - 1;
    int minSum = arr[left] + arr[right];
    int minLeft = arr[left], minRight = arr[right];

    while(left < right) {
        int sum = arr[left] + arr[right];

        if(abs(sum) < abs(minSum)) {
            minSum = sum;
            minLeft = arr[left];
            minRight = arr[right];
        }

        if(sum < 0)
            left++;
        else
            right--;
    }

    printf("%d %d\n", minLeft, minRight);

    return 0;
}
