#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct LinkedList {
    Node* head;
    Node* tail;
} LinkedList;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void insertFront(LinkedList* list, int data) {
    Node* node = createNode(data);
    if (list->head == NULL) {
        list->head = list->tail = node;
    } else {
        node->next = list->head;
        list->head->prev = node;
        list->head = node;
    }
}

void insertBack(LinkedList* list, int data) {
    Node* node = createNode(data);
    if (list->tail == NULL) {
        list->head = list->tail = node;
    } else {
        node->prev = list->tail;
        list->tail->next = node;
        list->tail = node;
    }
}

void deleteFront(LinkedList* list) {
    if (list->head == NULL) {
        return;
    }
    Node* temp = list->head;
    list->head = list->head->next;
    if (list->head != NULL) {
        list->head->prev = NULL;
    } else {
        list->tail = NULL;
    }
    free(temp);
}

void deleteBack(LinkedList* list) {
    if (list->tail == NULL) {
        return;
    }
    Node* temp = list->tail;
    list->tail = list->tail->prev;
    if (list->tail != NULL) {
        list->tail->next = NULL;
    } else {
        list->head = NULL;
    }
    free(temp);
}

void printForward(LinkedList* list) {
    Node* temp = list->head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void printBackward(LinkedList* list) {
    Node* temp = list->tail;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    LinkedList* list = createLinkedList();
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        insertBack(list, x);
    }
    for (int i = 0; i < q; i++) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            int x;
            scanf("%d", &x);
            insertFront(list, x);
        } else if (op == 2) {
            int x;
            scanf("%d", &x);
            insertBack(list, x);
        } else if (op == 3) {
            deleteFront(list);
        } else if (op == 4) {
            deleteBack(list);
        } else if (op == 5) {
            printForward(list);
        } else if (op == 6) {
            printBackward(list);
        }
    }
    return 0;
}