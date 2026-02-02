#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100004
#define MAX_STRLEN 21
#define TABLE_SIZE 130003

typedef struct Node {
    char str[MAX_STRLEN];
    struct Node* next;
    int cnt;
} Node;

Node* hash_table[TABLE_SIZE];

unsigned int hash(char* str) {
    unsigned int hash = 5381;
    unsigned int c;
    while(c = *str++) {
        hash = (hash << 5) + hash + c;
    }

    return hash % TABLE_SIZE;
}

int check(char* str, int cnt) {
    unsigned int idx = hash(str);

    Node* now = hash_table[idx];
    while(now) {
        if(strcmp(now->str, str) == 0) { // If exist,
            if(now->cnt == cnt) return 0; // If chatted already, return 0
            now->cnt = cnt; // First chat
            return 1;
        }
        now = now->next;
    }

    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->str, str);
    new_node->next = hash_table[idx];
    new_node->cnt = cnt;
    hash_table[idx] = new_node;

    return 1;
}

int main() {
    int N;
    scanf("%d", &N);

    char str[MAX_STRLEN];
    int cnt = 0;
    int answer = 0;
    for(int i=0;i<N;++i) {
        scanf("%s", str);
        if(strcmp(str, "ENTER") == 0) {
            cnt++;
        } else {
            answer += check(str, cnt);
        }
    }

    printf("%d\n", answer);

    return 0;
}