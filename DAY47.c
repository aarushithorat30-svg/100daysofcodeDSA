#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int height(struct Node* root) {
    if (root == NULL)
        return 0;
    int l = height(root->left);
    int r = height(root->right);
    return (l > r ? l : r) + 1;
}

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) {
        printf("0");
        return 0;
    }

    struct Node** nodes = (struct Node**)malloc(n * sizeof(struct Node*));

    for (int i = 0; i < n; i++) {
        nodes[i] = newNode(0);
    }

    for (int i = 0; i < n; i++) {
        int val, l, r;
        scanf("%d %d %d", &val, &l, &r);
        nodes[i]->data = val;
        if (l != -1)
            nodes[i]->left = nodes[l];
        if (r != -1)
            nodes[i]->right = nodes[r];
    }

    printf("%d", height(nodes[0]));
    return 0;
}