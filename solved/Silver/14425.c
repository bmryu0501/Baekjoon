#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRLEN 501
#define TABLE_SIZE 20011

typedef struct Node {
    char str[MAX_STRLEN];
    struct Node* next;
} Node;

Node* hash_table[TABLE_SIZE];

unsigned int hash(const char* str) {
    unsigned int hash = 5381;
    int c;
    while((c = *str++)) {
        hash = (hash << 5) + hash + c;
    }
    return hash % TABLE_SIZE;
}

void insert(char* str) {
    unsigned int idx = hash(str);
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->str, str);
    new_node->next = hash_table[idx];
    hash_table[idx] = new_node;
}

int search(char* str) {
    unsigned int idx = hash(str);
    Node* now = hash_table[idx];
    while(now != NULL) {
        if(strcmp(now->str, str) == 0) return 1;
        now = now->next;
    }
    return 0;
}

int main() {
    int N, M;
    int cnt = 0;
    char target[MAX_STRLEN];
    scanf("%d %d", &N, &M);

    for(int i=0;i<N;++i) {
        scanf("%s", target);
        insert(target);
    }

    for(int i=0;i<M;++i) {
        scanf("%s", target);
        cnt += search(target);
    }

    printf("%d\n", cnt);

    return 0;
}