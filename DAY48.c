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

int countLeaves(struct Node* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeaves(root->left) + countLeaves(root->right);
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

    printf("%d", countLeaves(nodes[0]));
    return 0;
}