#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = v;
    newNode->next = NULL;
    return newNode;
}

void dfs(int v, struct Node* adj[], int visited[]) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = adj[v];
    while (temp) {
        if (!visited[temp->val]) {
            dfs(temp->val, adj, visited);
        }
        temp = temp->next;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];
    for (int i = 0; i < n; i++) adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        struct Node* newNode = createNode(v);
        newNode->next = adj[u];
        adj[u] = newNode;

        newNode = createNode(u);
        newNode->next = adj[v];
        adj[v] = newNode;
    }

    int s;
    scanf("%d", &s);

    int visited[n];
    for (int i = 0; i < n; i++) visited[i] = 0;

    dfs(s, adj, visited);

    return 0;
}