#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000005

typedef struct Stack {
    int data[MAX_SIZE];
    int top;
} Stack;

Stack stack;

int push() {
    int val;
    scanf("%d", &val);
    Stack* s = &stack;
    if(s->top > MAX_SIZE) return 0;
    s->data[(s->top)++] = val;
    return 1;
}

int pop() {
    Stack* s = &stack;
    if(s->top == 0) return -1;
    return s->data[--(s->top)];
}

int size() {
    Stack* s = &stack;
    return s->top;
}

int isEmpty() {
    Stack* s = &stack;
    return (s->top==0)?1:0;
}

int top() {
    Stack* s = &stack;
    return (s->top>0)?(s->data[s->top-1]):-1;
}

int main() {
    int (*fp[6])();
    fp[1] = push;
    fp[2] = pop;
    fp[3] = size;
    fp[4] = isEmpty;
    fp[5] = top;

    int N;
    scanf("%d", &N);
    stack.top = 0;

    int op;
    for(int i=0;i<N;++i) {
        scanf("%d", &op);
        if(op == 1) push();
        else printf("%d\n", fp[op]());
    }

    return 0;
}