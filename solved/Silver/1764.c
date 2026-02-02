#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 500005
#define MAX_M 500005
#define MAX_STRLEN 21
#define TABLE_SIZE 1000003

typedef struct Node {
    char name[MAX_STRLEN];
    struct Node* next;
} Node;

Node* hash_table[TABLE_SIZE];
char buffer[MAX_N][MAX_STRLEN];

unsigned hash(const char*);
void insert(const char*);
int search(const char*);
int compare_string(const void*, const void*);

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    char name[MAX_STRLEN];
    for(int i=0;i<N;++i) {
        scanf("%s", name);
        insert(name);
    }

    int idx = 0;
    for(int i=0;i<M;++i) {
        scanf("%s", name);
        if(search(name)) {
            strcpy(buffer[idx++], name);
        }
    }

    printf("%d\n", idx);
    qsort(buffer, idx, sizeof(buffer[0]), compare_string);
    for(int i=0;i<idx;++i) printf("%s\n", buffer[i]);

    // free memory
    for(int i=0;i<TABLE_SIZE;++i) {
        Node* now = hash_table[i];
        while(now){
            Node* temp = now;
            now = now->next;
            free(temp);
        }
    }

    return 0;
}

unsigned int hash(const char* name) {
    unsigned int hash = 5381;
    int c;
    while(c = *name++) {
        hash = (hash << 5) + hash + c;
    }
    return hash % TABLE_SIZE;
}

void insert(const char* name) {
    unsigned int idx = hash(name);
    Node* new_node = (Node*)malloc(sizeof(Node));
    strcpy(new_node->name, name);
    new_node->next = hash_table[idx];
    hash_table[idx] = new_node;

    return;
}

int search(const char* name) {
    unsigned int idx = hash(name);
    Node* now = hash_table[idx];
    while(now) {
        if(strcmp(name, now->name) == 0) return 1;
        now = now->next;
    }

    return 0;
}

int compare_string(const void* a, const void* b) {
    const char *str1 = (const char*)a;
    const char *str2 = (const char*)b;
    return strcmp(str1, str2);
}
