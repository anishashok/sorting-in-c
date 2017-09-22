#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(int* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", *(a + i));
	}
	printf("\n");
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int* bubble_sort(int* a, int n) {
	int* result = malloc(n*sizeof(int));
	memcpy(result, a, n*sizeof(int));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-1; j++) {
			if(result[j] > result[j+1]) {
				swap(&result[j], &result[j+1]);
			}
		}
	}
	return result;
}

int main(int argc, char** argv) {
	int n = argc - 1;
	char** arr = argv + 1;
	int* numbers = malloc(n*sizeof(int));
	for (int i = 0; i < n; i++) {
		*(numbers + i) = atoi(*(arr + i));
	}
	int* sorted = bubble_sort(numbers, n);
	printArray(sorted, n);
	free(sorted);
	return 0;
}

