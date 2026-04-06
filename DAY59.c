#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};

struct Node* build(int* inorder, int inStart, int inEnd, int* postorder, int* postIndex) {
    if (inStart > inEnd) return NULL;

    int rootVal = postorder[*postIndex];
    (*postIndex)--;

    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->val = rootVal;
    root->left = root->right = NULL;

    int i;
    for (i = inStart; i <= inEnd; i++) {
        if (inorder[i] == rootVal) break;
    }

    root->right = build(inorder, i + 1, inEnd, postorder, postIndex);
    root->left = build(inorder, inStart, i - 1, postorder, postIndex);

    return root;
}

void preorder(struct Node* root) {
    if (!root) return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

int main() {
    int n;
    scanf("%d", &n);

    int inorder[n], postorder[n];

    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &postorder[i]);

    int postIndex = n - 1;

    struct Node* root = build(inorder, 0, n - 1, postorder, &postIndex);

    preorder(root);

    return 0;
}