#include <stdio.h>

#define MAX 1000

int queue[MAX];
int stack[MAX];

int main(){
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++) scanf("%d",&queue[i]);

    int top=-1;

    for(int i=0;i<n;i++) stack[++top]=queue[i];

    int idx=0;

    while(top>=0) queue[idx++]=stack[top--];

    for(int i=0;i<n;i++) printf("%d ",queue[i]);

    return 0;
}