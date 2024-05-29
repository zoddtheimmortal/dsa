#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    int time;
    struct Node* next;
} Node;

typedef struct Heap {
    Node* head;
    int size;
    int sum;
} Heap;

Heap* createHeap() {
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->head = NULL;
    heap->size = 0;
    heap->sum = 0;
    return heap;
}

void push(Heap* heap, int val, int time) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->time = time;
    node->next = heap->head;
    heap->head = node;
    heap->size++;
    heap->sum += val;
}

int pop(Heap* heap) {
    if (heap->size == 0) {
        return -1;
    }
    Node* temp = heap->head;
    int val = temp->val;
    heap->head = heap->head->next;
    free(temp);
    heap->size--;
    heap->sum -= val;
    return val;
}

int getMin(Heap* heap) {
    Node* temp = heap->head;
    int min = temp->val;
    while (temp != NULL) {
        if (temp->val < min) {
            min = temp->val;
        }
        temp = temp->next;
    }
    return min;
}

int getAvg(Heap* heap) {
    return heap->sum / heap->size;
}

int main() {
    int q;
    scanf("%d", &q);
    Heap* stack = createHeap();
    Heap* queue = createHeap();
    for (int i = 0; i < q; i++) {
        int type;
        scanf("%d", &type);
        if (type == 1) {
            int x;
            scanf("%d", &x);
            push(stack, x, i);
            push(queue, x, i);
        } else if (type == 2) {
            pop(stack);
            pop(queue);
        } else if (type == 3) {
            printf("%d %d\n", getMin(stack), getAvg(queue));
        }
    }
    return 0;
}