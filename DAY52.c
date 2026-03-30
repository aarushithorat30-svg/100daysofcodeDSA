#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
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

struct Node* lca(struct Node* root, int a, int b) {
    if (root == NULL || root->data == a || root->data == b)
        return root;

    struct Node* left = lca(root->left, a, b);
    struct Node* right = lca(root->right, a, b);

    if (left && right)
        return root;

    return left ? left : right;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[1000];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int a, b;
    scanf("%d %d", &a, &b);

    struct Node* root = buildTree(arr, n);
    struct Node* ans = lca(root, a, b);

    if (ans)
        printf("%d", ans->data);

    return 0;
}