#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Node {
    int val;
    int arrIdx;
    int nextIdx;
} Node;

void swap(Node* a, Node* b) {
    Node temp = *a;
    *a = *b;
    *b = temp;
}

void minHeapify(Node heap[], int i, int heapSize) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heapSize && heap[left].val < heap[smallest].val)
        smallest = left;

    if (right < heapSize && heap[right].val < heap[smallest].val)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(heap, smallest, heapSize);
    }
}

void buildMinHeap(Node heap[], int heapSize) {
    int i;
    for (i = (heapSize - 2) / 2; i >= 0; i--)
        minHeapify(heap, i, heapSize);
}

void mergeKSortedArrays(int** arrays, int arraySizes[], int k) {
    Node* heap = (Node*)malloc(sizeof(Node) * k);
    int i;
    for (i = 0; i < k; i++) {
        heap[i].val = arrays[i][0];
        heap[i].arrIdx = i;
        heap[i].nextIdx = 1;
    }

    buildMinHeap(heap, k);

    while (1) {
        Node root = heap[0];

        printf("%d ", root.val);

        if (root.nextIdx < arraySizes[root.arrIdx])
            root.val = arrays[root.arrIdx][root.nextIdx++];
        else
            root.val = INT_MAX;

        heap[0] = root;
        minHeapify(heap, 0, k);

        if (heap[0].val == INT_MAX) break;
    }

    free(heap);
}

int main() {
    int k;
    scanf("%d", &k);

    int** arrays = (int**)malloc(sizeof(int*) * k);
    int* arraySizes = (int*)malloc(sizeof(int) * k);

    int i, j;
    for (i = 0; i < k; i++) {
        scanf("%d", &arraySizes[i]);
        arrays[i] = (int*)malloc(sizeof(int) * arraySizes[i]);
        for (j = 0; j < arraySizes[i]; j++)
            scanf("%d", &arrays[i][j]);
    }

    mergeKSortedArrays(arrays, arraySizes, k);

    for (i = 0; i < k; i++) free(arrays[i]);
    free(arrays);
    free(arraySizes);

    return 0;
}