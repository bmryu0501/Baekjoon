#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 6
#define MAX_N 1000005
#define TABLE_SIZE 20011

typedef struct Node {
    char name[MAX_LEN];
    struct Node* prev;
    struct Node* next;
} Node;

Node* hash_table[TABLE_SIZE];
char names[MAX_N][MAX_LEN];

unsigned int hash(char* name) {
    unsigned int hash = 5381;
    int c;
    while(c = *name++) {
        hash = (hash << 5) + hash + c;
    }
    return hash % TABLE_SIZE;
}

void insert(char* name) {
    unsigned int idx = hash(name);
    Node* new_node = (Node*)malloc(sizeof(Node));
    memset(new_node, 0, sizeof(Node));
    strcpy(new_node->name, name);

    new_node->next = hash_table[idx];
    if (hash_table[idx] != NULL) {
        hash_table[idx]->prev = new_node;
    }
    hash_table[idx] = new_node;
}

void removeNode(char* name) {
    unsigned int idx = hash(name);
    Node* now = hash_table[idx];

    while (now != NULL) {
        if (strcmp(now->name, name) == 0) {
            if (now->prev != NULL) {
                now->prev->next = now->next;
            } else {
                hash_table[idx] = now->next;  // 첫 번째 노드 삭제 처리
            }
            if (now->next != NULL) {
                now->next->prev = now->prev;
            }
            free(now);
            return;
        }
        now = now->next;
    }
}

int compare(const void* str1, const void* str2) {
    return strcmp((char*)str1, (char*)str2) * -1;
}

int main() {
    int N;
    int count = 0;
    char name[MAX_LEN];
    char act[MAX_LEN];

    scanf("%d", &N);
    for(int i=0;i<N;++i) {
        scanf("%s %s", name, act);
        if(strcmp(act, "enter") == 0) {
            insert(name);
            count++;
        } else {
            removeNode(name);
            count--;
        }
    }

    int idx = 0;
    for(int i=0;i<TABLE_SIZE;++i) {
        Node* now = hash_table[i];
        while(now) {
            strcpy(names[idx++], now->name);
            now = now->next;
        }
    }

    qsort(names, count, sizeof(char)*MAX_LEN, compare);
    for(int i=0;i<idx;++i) printf("%s\n", names[i]);

    return 0;
}