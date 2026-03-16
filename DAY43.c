#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* createNode(int x){
    Node* n=(Node*)malloc(sizeof(Node));
    n->data=x;
    n->left=NULL;
    n->right=NULL;
    return n;
}

Node* buildTree(int arr[],int n){
    if(n==0 || arr[0]==-1) return NULL;

    Node* root=createNode(arr[0]);

    Node* queue[1000];
    int front=0,rear=0;

    queue[rear++]=root;
    int i=1;

    while(front<rear && i<n){
        Node* curr=queue[front++];

        if(i<n && arr[i]!=-1){
            curr->left=createNode(arr[i]);
            queue[rear++]=curr->left;
        }
        i++;

        if(i<n && arr[i]!=-1){
            curr->right=createNode(arr[i]);
            queue[rear++]=curr->right;
        }
        i++;
    }

    return root;
}

void inorder(Node* root){
    if(root==NULL) return;
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
}

int main(){
    int n;
    scanf("%d",&n);

    int arr[n];

    for(int i=0;i<n;i++) scanf("%d",&arr[i]);

    Node* root=buildTree(arr,n);

    inorder(root);

    return 0;
}