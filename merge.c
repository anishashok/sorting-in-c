#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(int a[], int n) {
	for (int i = 0; i < n; i++) 
		printf("%d ", a[i]);
	printf("\n");
}

void merge(int a[], int low, int mid, int high) {
	int n1 = mid - low + 1, n2 = high - mid;
	int b1[n1], b2[n2];
	for (int i = 0; i < n1; i++)
		b1[i] = a[low + i];
	for (int i = 0; i < n2; i++)
		b2[i] = a[mid+1 + i];
	
	int i=0, j=0, k=low;
	while (i < n1 && j < n2) {
		if (b1[i] <= b2[j])
			a[k] = b1[i++];
		else
			a[k] = b2[j++];
		k++;
	}
	while (i < n1)
		a[k++] = b1[i++];
	while (j < n2)
		a[k++] = b2[j++];
}

void merge_sort(int a[], int low, int high) {
	int mid;
	if (low < high) {
		mid = (low+high) / 2;
		merge_sort(a, low, mid);
		merge_sort(a, mid+1, high);
		merge(a, low, mid, high);
	}
}

int main(int argc, char** argv) {
	int n = argc - 1;
	char** arr = argv + 1;
	int numbers[n];
	for (int i = 0; i < n; i++) 
		numbers[i] = atoi(*(arr + i));
	merge_sort(numbers, 0, n-1);
	printArray(numbers, n);
	return 0;
}

