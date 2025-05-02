#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ======= Struct ========
typedef struct {
    char ID[10];
    char name[50];
    int studentCount;
} Class;

typedef struct NodeClass {
    Class data;
    struct NodeClass* next;
} NodeClass;

// ======= 1. initNodeClass ========
void initNodeClass(NodeClass*& s) {
    s = NULL;
}

// ======= 2. createNodeClass ========
NodeClass* createNodeClass(Class data) {
    NodeClass* node = (NodeClass*)malloc(sizeof(NodeClass));
    node->data = data;
    node->next = NULL;
    return node;
}

// ======= 3. addClass ========
void addClass(NodeClass*& s, Class data) {
    NodeClass* newNode = createNodeClass(data);
    newNode->next = s;
    s = newNode;
}

// ======= 4. deleteClass ========
Class deleteClass(NodeClass*& s, Class data) {
    NodeClass* prev = NULL;
    NodeClass* curr = s;
    while (curr != NULL && strcmp(curr->data.ID, data.ID) != 0) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("Class not found\n");
        Class empty = {"", "", 0};
        return empty;
    }

    if (prev == NULL) s = curr->next;
    else prev->next = curr->next;

    Class deleted = curr->data;
    free(curr);
    return deleted;
}

// ======= 5. SearchClass ========
NodeClass* SearchClass(NodeClass* s, Class data) {
    while (s != NULL) {
        if (strcmp(s->data.ID, data.ID) == 0)
            return s;
        s = s->next;
    }
    return NULL;
}

// ======= 6. changeClassInfo ========
void changeClassInfo(NodeClass* s, char ID[]) {
    while (s != NULL) {
        if (strcmp(s->data.ID, ID) == 0) {
            printf("Nhap ten moi: ");
            scanf(" %[^\n]", s->data.name);
            printf("Nhap so hoc vien moi: ");
            scanf("%d", &s->data.studentCount);
            return;
        }
        s = s->next;
    }
    printf("Khong tim thay lop co ID: %s\n", ID);
}
