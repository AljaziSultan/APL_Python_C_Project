#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }
    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

int main() {
    int n, choice, val, index;
    
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Original array: ");
    printArray(arr, n);
    
    printf("Choose a sorting algorithm:\n");
printf("1. Insertion sort\n");
    printf("2. Merge sort\n");
    printf("3. Quick sort\n");
    printf("4. Heap sort\n");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            insertionSort(arr, n);
            printf("Array sorted using insertion sort: ");
            printArray(arr, n);
            break;
        case 2:
            mergeSort(arr, 0, n - 1);
            printf("Array sorted using merge sort: ");
            printArray(arr, n);
            break;
        case 3:
            quickSort(arr, 0, n - 1);
            printf("Array sorted using quick sort: ");
            printArray(arr, n);
            break;
        case 4:
            heapSort(arr, n);
            printf("Array sorted using heap sort: ");
            printArray(arr, n);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
    
    printf("Enter an index to delete: ");
    scanf("%d", &index);
    if (index < 0 || index >= n) {
        printf("Invalid index\n");
    }
    else {
        for (int i = index; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
        printf("Array after deleting element at index %d: ", index);
        printArray(arr, n);
    }
    
    printf("Enter a value to insert: ");
    scanf("%d", &val);
    printf("Enter an index to insert at: ");
    scanf("%d", &index);
    if (index < 0 || index > n) {
        printf("Invalid index\n");
    }
    else {
        for (int i = n - 1; i >= index; i--) {
            arr[i + 1] = arr[i];
        }
        arr[index] = val;
        n++;
        printf("Array after inserting %d at index %d: ", val, index);
        printArray(arr, n);
    }
    
    printf("Enter an index to update: ");
    scanf("%d", &index);
    if (index < 0 || index >= n) {
        printf("Invalid index\n");
    }
    else {
        printf("Enter a new value: ");
        scanf("%d", &val);
        arr[index] = val;
        printf("Array after updating element at index %d: ", index);
        printArray(arr, n);
    }
    
    return 0;
}