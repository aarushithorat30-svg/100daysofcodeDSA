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

int find(int inorder[], int start, int end, int val) {
    for (int i = start; i <= end; i++)
        if (inorder[i] == val)
            return i;
    return -1;
}

struct Node* build(int preorder[], int inorder[], int ps, int pe, int is, int ie) {
    if (ps > pe || is > ie)
        return NULL;

    struct Node* root = create(preorder[ps]);
    int k = find(inorder, is, ie, root->data);
    int leftSize = k - is;

    root->left = build(preorder, inorder, ps + 1, ps + leftSize, is, k - 1);
    root->right = build(preorder, inorder, ps + leftSize + 1, pe, k + 1, ie);

    return root;
}

void postorder(struct Node* root) {
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main() {
    int n;
    scanf("%d", &n);

    int preorder[1000], inorder[1000];

    for (int i = 0; i < n; i++)
        scanf("%d", &preorder[i]);

    for (int i = 0; i < n; i++)
        scanf("%d", &inorder[i]);

    struct Node* root = build(preorder, inorder, 0, n - 1, 0, n - 1);

    postorder(root);

    return 0;
}