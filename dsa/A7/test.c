#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void insert(int heap[], int value, int* size) {
    int i = *size;
    heap[i] = value;

    while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }

    (*size)++;
}

void deleteRoot(int heap[], int* size) {
    heap[0] = heap[*size - 1];
    (*size)--;
    heapify(heap, *size, 0);
}

int main() {
    int n, k, x;
    scanf("%d %d %d", &n, &k, &x);
    int heap[n];
    int size = 0;
    int map[n];
    for (int i = 0; i < n; i++) {
        int pos;
        scanf("%d", &pos);
        int dist = abs(x - pos);
        insert(heap, dist, &size);
        map[dist] = pos;
        if (size > k) {
            deleteRoot(heap, &size);
        }
    }
    for (int i = 0; i < k; i++) {
        printf("%d ", map[heap[i]]);
    }
    printf("\n");
    return 0;
}