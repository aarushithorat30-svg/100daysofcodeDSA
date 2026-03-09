#include <stdio.h>
#include <string.h>

int heap[1000];
int size=0;

void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}

void heapifyUp(int i){
    while(i>0){
        int p=(i-1)/2;
        if(heap[p]<=heap[i]) break;
        swap(&heap[p],&heap[i]);
        i=p;
    }
}

void heapifyDown(int i){
    while(1){
        int l=2*i+1;
        int r=2*i+2;
        int s=i;

        if(l<size && heap[l]<heap[s]) s=l;
        if(r<size && heap[r]<heap[s]) s=r;

        if(s==i) break;

        swap(&heap[i],&heap[s]);
        i=s;
    }
}

void insert(int x){
    heap[size]=x;
    heapifyUp(size);
    size++;
}

int delete(){
    if(size==0) return -1;

    int val=heap[0];
    heap[0]=heap[size-1];
    size--;
    heapifyDown(0);
    return val;
}

int peek(){
    if(size==0) return -1;
    return heap[0];
}

int main(){
    int n,x;
    char op[10];

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%s",op);

        if(strcmp(op,"insert")==0){
            scanf("%d",&x);
            insert(x);
        }
        else if(strcmp(op,"delete")==0){
            printf("%d\n",delete());
        }
        else if(strcmp(op,"peek")==0){
            printf("%d\n",peek());
        }
    }

    return 0;
}