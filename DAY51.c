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

struct Node* insert(struct Node* root, int val) {
    if (root == NULL)
        return create(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

struct Node* lca(struct Node* root, int a, int b) {
    if (root == NULL)
        return NULL;
    if (root->data > a && root->data > b)
        return lca(root->left, a, b);
    if (root->data < a && root->data < b)
        return lca(root->right, a, b);
    return root;
}

int main() {
    int n, x, a, b;
    struct Node* root = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    scanf("%d %d", &a, &b);

    struct Node* ans = lca(root, a, b);

    if (ans)
        printf("%d", ans->data);

    return 0;
}