#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* head = NULL;

Node* getNewNode(int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtHead(int x) {
    Node* newNode = getNewNode(x);
    if(head == NULL) {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head; 
    head = newNode;
}

void insertAtTail(int x) {
    Node* temp = head;
    Node* newNode = getNewNode(x);
    if(head == NULL) {
        head = newNode;
        return;
    }
    while(temp->next != NULL) temp = temp->next; 
    temp->next = newNode;
    newNode->prev = temp;
}

void print() {
    Node* temp = head;
    if(temp == NULL) {
        printf("-1\n");
        return;
    }
    while(temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reversePrint() {
    Node* temp = head;
    if(temp == NULL) {
        printf("-1\n");
        return;
    }
    while(temp->next != NULL) {
        temp = temp->next;
    }
    while(temp != NULL) {
        printf("%d ",temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    int n, q, i, op, x;
    scanf("%d %d", &n, &q);
    for(i = 0; i < n; i++) {
        scanf("%d", &x);
        insertAtTail(x);
    }
    for(i = 0; i < q; i++) {
        scanf("%d", &op);
        if(op == 1) {
            scanf("%d", &x);
            insertAtHead(x);
        } else if(op == 2) {
            scanf("%d", &x);
            insertAtTail(x);
        } else if(op == 3) {
            if(head != NULL) {
                Node* temp = head;
                head = head->next;
                if(head != NULL) head->prev = NULL;
                free(temp);
            }
        } else if(op == 4) {
            Node* temp = head;
            if(temp != NULL) {
                while(temp->next != NULL) temp = temp->next;
                if(temp->prev != NULL) temp->prev->next = NULL;
                else head = NULL;
                free(temp);
            }
        } else if(op == 5) {
            print();
        } else if(op == 6) {
            reversePrint();
        }
    }
    return 0;
}