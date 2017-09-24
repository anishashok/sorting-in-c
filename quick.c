#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

void printArray(int arr[], int n) {
	for (int i=0; i<n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void swap(int* a, int* b) {
	int temp = *b;
	*b = *a;
	*a = temp;
}

int partition(int arr[], int low, int high) {
	int i = low-1, j;
	for (j = low; j < high; j++) {
		if (arr[j] < arr[high])
			swap(&arr[++i], &arr[j]);
	}
        swap(&arr[++i], &arr[high]);
	return i;
}

void quick_sort(int arr[], int low, int high) {
	int index;
	if (low < high) {
		index = partition(arr, low, high);
		quick_sort(arr, low, index-1);
		quick_sort(arr, index+1, high);
	}
}

int main(int argc, char* argv[]) {
	int n = argc - 1;
	char** arr = argv + 1;
	int numbers[n];
	for (int i = 0; i < n; i++)
		numbers[i] = atoi(*(arr + i));
	quick_sort(numbers, 0, n-1);
	printArray(numbers, n);
	return 0;
}
