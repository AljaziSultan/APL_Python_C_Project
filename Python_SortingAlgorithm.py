def printArray(arr):
    for i in arr:
        print(i, end=" ")
    print()

def insertionSort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def merge(arr, l, m, r):
    n1 = m - l + 1
    n2 = r - m
    L = [0] * n1
    R = [0] * n2
    for i in range(n1):
        L[i] = arr[l + i]
    for j in range(n2):
        R[j] = arr[m + 1 + j]
    i = 0
    j = 0
    k = l
    while i < n1 and j < n2:
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1
    while i < n1:
        arr[k] = L[i]
        i += 1
        k += 1
    while j < n2:
        arr[k] = R[j]
        j += 1
        k += 1

def mergeSort(arr, l, r):
    if l < r:
        m = (l + r) // 2
        mergeSort(arr, l, m)
        mergeSort(arr, m + 1, r)
        merge(arr, l, m, r)

def partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

def quickSort(arr, low, high):
    if low < high:
        pi = partition(arr, low, high)
        quickSort(arr, low, pi - 1)
        quickSort(arr, pi + 1, high)

def heapify(arr, n, i):
    largest = i
    l = 2 * i + 1
    r = 2 * i + 2
    if l < n and arr[l] > arr[largest]:
        largest = l
    if r < n and arr[r] > arr[largest]:
        largest = r
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)

def heapSort(arr):
    n = len(arr)
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)
    for i in range(n - 1, 0, -1):
        arr[i], arr[0] = arr[0], arr[i]
        heapify(arr, i, 0)

n = int(input("Enter the size of the array: "))
arr = []
print("Enter", n, "elements:")
for _ in range(n):
    arr.append(int(input()))
    
print("Original array: ", end="")
printArray(arr)

print("Choose a sorting algorithm:")
print("1. Insertion sort")
print("2. Merge sort")
print("3. Quick sort")
print("4. Heap sort")
choice = int(input())

if choice == 1:
    insertionSort(arr)
    print("Array sorted using insertion sort: ", end="")
    printArray(arr)
elif choice == 2:
    mergeSort(arr, 0, n - 1)
    print("Array sorted using merge sort: ", end="")
    printArray(arr)
elif choice == 3:
    quickSort(arr, 0, n - 1)
    print("Array sorted using quick sort: ", end="")
    printArray(arr)
elif choice == 4:
    heapSort(arr)
    print("Array sorted using heap sort: ", end="")
    printArray(arr)
else:
    print("Invalid choice")

index = int(input("Enter an index to delete: "))
if index < 0 or index >= n:
    print("Invalid index")
else:
    del arr[index]
    n -= 1
    print("Array after deleting element at index", index, ": ", end="")
    printArray(arr)

val = int(input("Enter a value to insert: "))
index = int(input("Enter an index to insert at: "))
if index < 0 or index > n:
    print("Invalid index")
else:
    arr.append(0)
    for i in range(n, index, -1):
        arr[i] = arr[i - 1]
    arr[index] = val
    n += 1
    print("Array after inserting", val, "at index", index, ": ", end="")
    printArray(arr)

index = int(input("Enter an index to update: "))
if index < 0 or index >= n:
    print("Invalid index")
else:
    val = int(input("Enter a new value: "))
    arr[index] = val
    print("Array after updating element at index", index, ": ", end="")
    printArray(arr)