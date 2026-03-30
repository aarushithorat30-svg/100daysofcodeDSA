#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct QNode {
    struct Node* node;
    int hd;
};

struct Node* create(int val) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val;
    n->left = n->right = NULL;
    return n;
}

struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1)
        return NULL;

    struct Node* root = create(arr[0]);
    struct Node* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int i = 1;

    while (i < n) {
        struct Node* curr = queue[front++];

        if (arr[i] != -1) {
            curr->left = create(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = create(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }

    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);

    struct QNode queue[1000];
    int front = 0, rear = 0;

    int map[2000][100];
    int count[2000] = {0};

    int min = 1000, max = 1000;

    queue[rear++] = (struct QNode){root, 1000};

    while (front < rear) {
        struct QNode temp = queue[front++];
        struct Node* node = temp.node;
        int hd = temp.hd;

        map[hd][count[hd]++] = node->data;

        if (hd < min) min = hd;
        if (hd > max) max = hd;

        if (node->left)
            queue[rear++] = (struct QNode){node->left, hd - 1};
        if (node->right)
            queue[rear++] = (struct QNode){node->right, hd + 1};
    }

    for (int i = min; i <= max; i++) {
        for (int j = 0; j < count[i]; j++)
            printf("%d ", map[i][j]);
        printf("\n");
    }

    return 0;
}