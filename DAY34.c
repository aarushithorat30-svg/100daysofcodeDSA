#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int data;
    struct node* next;
};

struct node* top = NULL;

void push(int x){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

int pop(){
    int x = top->data;
    struct node* temp = top;
    top = top->next;
    free(temp);
    return x;
}

int main(){
    char exp[100];
    char *t;
    int a,b,res;

    printf("Enter postfix expression: ");
    fgets(exp,100,stdin);

    t = strtok(exp," ");

    while(t!=NULL){
        if(t[0]>='0' && t[0]<='9'){
            push(atoi(t));
        }
        else{
            b = pop();
            a = pop();

            if(t[0]=='+') res = a+b;
            if(t[0]=='-') res = a-b;
            if(t[0]=='*') res = a*b;
            if(t[0]=='/') res = a/b;

            push(res);
        }
        t = strtok(NULL," ");
    }

    printf("Result: %d", pop());
    return 0;
}