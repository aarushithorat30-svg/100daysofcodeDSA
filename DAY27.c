#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;

    for(int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }
    return head;
}

int getLength(struct Node* head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

struct Node* getIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    struct Node *ptr1 = head1, *ptr2 = head2;

    int diff = abs(len1 - len2);

    if(len1 > len2) {
        for(int i = 0; i < diff; i++)
            ptr1 = ptr1->next;
    } else {
        for(int i = 0; i < diff; i++)
            ptr2 = ptr2->next;
    }

    while(ptr1 != NULL && ptr2 != NULL) {
        if(ptr1 == ptr2)
            return ptr1;

        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return NULL;
}

struct Node* findNode(struct Node* head, int value) {
    while(head != NULL) {
        if(head->data == value)
            return head;
        head = head->next;
    }
    return NULL;
}

int main() {
    int n, m;

    scanf("%d", &n);
    struct Node* head1 = createList(n);

    scanf("%d", &m);
    struct Node* head2 = createList(m);

    struct Node* temp = head2;
    while(temp->next != NULL)
        temp = temp->next;

    struct Node* intersectNode = findNode(head1, temp->data);
    if(intersectNode != NULL)
        temp->next = intersectNode;

    struct Node* result = getIntersection(head1, head2);

    if(result != NULL)
        printf("%d\n", result->data);
    else
        printf("No Intersection\n");

    return 0;
}