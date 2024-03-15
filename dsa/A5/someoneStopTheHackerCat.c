#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* prev;
    struct Node* next;
} Node;

Node* add_end(Node* tail, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->next = NULL;
    if (tail != NULL) {
        tail->next = new_node;
        new_node->prev = tail;
    } else {
        new_node->prev = NULL;
    }
    return new_node;
}

Node* add_next(Node* current, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->value = value;
    new_node->prev = current;
    new_node->next = current->next;
    if (current->next != NULL) {
        current->next->prev = new_node;
    }
    current->next = new_node;
    return new_node;
}

void delete(Node** head, Node** tail, Node** current) {
    Node* next_song = (*current)->next != NULL ? (*current)->next : (*current)->prev;
    if ((*current)->prev != NULL) {
        (*current)->prev->next = (*current)->next;
    } else {
        *head = (*current)->next;
    }
    if ((*current)->next != NULL) {
        (*current)->next->prev = (*current)->prev;
    } else {
        *tail = (*current)->prev;
    }
    free(*current);
    *current = next_song;
}

Node* get_next(Node* current) {
    return current->next != NULL ? current->next : current;
}

Node* get_prev(Node* current) {
    return current->prev != NULL ? current->prev : current;
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    Node* head = NULL;
    Node* tail = NULL;
    for (int i = 0; i < n; i++) {
        int song;
        scanf("%d", &song);
        tail = add_end(tail, song);
        if (head == NULL) {
            head = tail;
        }
    }
    Node* current = head;
    for (int i = 0; i < q; i++) {
        int operation;
        scanf("%d", &operation);
        if (operation == 1) {
            printf("%d\n", current != NULL ? current->value : 0);
        } else if (operation == 2) {
            int song;
            scanf("%d", &song);
            add_next(current, song);
        } else if (operation == 3) {
            int song;
            scanf("%d", &song);
            tail = add_end(tail, song);
        } else if (operation == 4) {
            current = get_next(current);
        } else if (operation == 5) {
            current = get_prev(current);
        } else if (operation == 6) {
            delete(&head, &tail, &current);
        }
    }
    return 0;
}