#include <stdio.h>

// function to swap two numbers
void swap(int *num1, int *num2) {
  int tmp = *num1;
  *num1 = *num2;
  *num2 = tmp;
}

// function to implement selection sort recursively
void selectionsort(int *arr, int n) {
  
}

int main(void) {
  
  // inputting the size of array
  printf("Enter the number of elements in array : ");
  int n; scanf("%d", &n);
  int arr[n];

  // inputting the array
  printf("\nEnter the elements in array: ");
  for(int i=0; i<n; i++) scanf("%d", &arr[i]);

  // Iterative Approach
  for(int i=0; i<n-1; i++) {
    int min = i;
    for(int j=i+1; j<n; j++) {
      if(arr[j] < arr[min]) min = j;
    }
    swap(&arr[i], &arr[min]);
  }

  printf("\nArray after Iterative Sort : ");
  for(int i=0; i<n; i++) printf("%d ", arr[i]);

  // Recursive Approach
  selectionsort(arr, n);
  
  return 0;
}
