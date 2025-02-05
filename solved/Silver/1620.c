#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 100005
#define MAX_M 100005
#define MAX_STRLEN 21
#define TABLE_SIZE 20011

typedef struct Node {
    char name[MAX_STRLEN];
    int number;
    struct Node* next;
} Node;

Node* hash_table[TABLE_SIZE];
Node pokemon[MAX_N];

unsigned int hash(char*);
void insert(char*, int);
int search(char*);

int main() {
    int N, M;
    char name[MAX_STRLEN];
    scanf("%d %d", &N, &M);
    for(int i=1;i<=N;++i) {
        scanf("%s", &name);
        insert(name, i);
    }

    for(int i=0;i<M;++i) {
        scanf("%s", &name);
        if(name[0] >= '0' && name[0] <= '9') {
            int num = strtol(name, NULL, 10);
            printf("%s\n", pokemon[num].name);
        } else {
            printf("%d\n", search(name));
        }
    }

    return 0;
}

unsigned int hash(char* str) {
    unsigned int hash = 5381;
    int c;
    while(c = *str++) {
        hash = ((hash << 5)%TABLE_SIZE + hash + c)%TABLE_SIZE;
    }

    return hash % TABLE_SIZE;
}

void insert(char* name, int num) {
    unsigned int idx = hash(name);
    if(hash_table[idx]) pokemon[num].next = hash_table[idx];
    hash_table[idx] = &pokemon[num];
    strcpy(pokemon[num].name, name);
    pokemon[num].number = num;

    return;
}

int search(char* name) {
    unsigned int idx = hash(name);
    Node* now = hash_table[idx];
    while(now) {
        //printf("Finding[%s], compare with[%s]\n", name, now->name);
        if(strcmp(now->name, name) == 0) return now->number;
        now = now->next;
    }

    return -1;
}