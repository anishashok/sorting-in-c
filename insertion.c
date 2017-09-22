#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printArray(int* a, int n) {
	for (int i = 0; i < n; i++) {
		printf("%d ", *(a + i));
	}
	printf("\n");
}

int* insertion_sort(int* a, int n) {
	int* result = malloc(n*sizeof(int));
	memcpy(result, a, n*sizeof(int));
	
	int j;
	for (int i = 0; i < n; i++) {
		j = i - 1;
		while(j > 0 && result[j] > a[i]) {
			result[j+1] = result[j];
			j = j - 1;
		}
		result[j+1] = a[i];	
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
	int* sorted = insertion_sort(numbers, n);
	printArray(sorted, n);
	free(sorted);
	return 0;
}

