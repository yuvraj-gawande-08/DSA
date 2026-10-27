#include <stdio.h>
// Function declarations
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void mergeSort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);
void swap(int *a, int *b);
void printArray(int arr[], int n);

int main()
{
    int arr[] = {50, 30, 40, 10, 20};
    int n = 5;
    int choice;
    printf("Choose Sorting Method:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Quick Sort\n");
    printf("4. Merge Sort\n");
    printf("5. Insertion Sort\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        bubbleSort(arr, n);
        printf("Bubble Sort: ");
        printArray(arr, n);
        break;
    case 2:
        selectionSort(arr, n);

        printf("Selection Sort: ");
        printArray(arr, n);
        break;
    case 3:
        quickSort(arr, 0, n - 1);
        printf("Quick Sort: ");
        printArray(arr, n);
        break;
    case 4:
        mergeSort(arr, 0, n - 1);
        printf("Merge Sort: ");
        printArray(arr, n);
        break;
    case 5:
        insertionSort(arr, n);
        printf("Insertion Sort: ");
        printArray(arr, n);
        break;
    default:
        printf("Invalid choice!");
    }
    return 0;
}

// 1. Bubble Sort
void bubbleSort(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];

                arr[j + 1] = temp;
            }
        }
    }
}

// 2. Selection Sort
void selectionSort(int arr[], int n)
{
    int minIndex;
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

// 3. Quick Sort
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// 4. Merge Sort
void mergeSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int mid = (low + high) / 2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

void merge(int arr[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;
    int sortedArray[100];
    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            sortedArray[k] = arr[i];
            i++;
        }
        else
        {
            sortedArray[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        sortedArray[k] = arr[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        sortedArray[k] = arr[j];
        j++;
        k++;
    }
    for (i = low; i <= high; i++)
    {
        arr[i] = sortedArray[i];
    }
}

// 5. Insertion Sort
void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Print Array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
