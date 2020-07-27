#include <stdio.h>

// function to swap two numbers
void swap(int *num1, int *num2) {
  int tmp = *num1;
  *num1 = *num2;
  *num2 = tmp;
}

// function to implement insertion sort recursively
/* TRACE TO UNDERSTAND */
void insertionsort(int arr[], int n) {
  if(n == 1) return;

  // sort the last n-1 elements
  insertionsort(arr, n-1);
  int d = n-2;
  int last = arr[n-1];
  while(d>=0 && arr[d] > last) {
    arr[d+1] = arr[d];
    d--;
  }
  arr[d+1] = last;
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
  for(int i=1; i<n; i++) {
    int d = i;
    while(d>0 && arr[d-1]>arr[d]) {
      swap(&arr[d-1], &arr[d]);
      d--;
    }
  }

  printf("Array after Iterative Sort : ");
  for(int i=0; i<n; i++) printf("%d ", arr[i]);

  // Recursive Approach
  insertionsort(arr, n);
  printf("\nArray after Recursive Sort : ");
  for(int i=0;i<n;i++) printf("%d ", arr[i]);

  return 0;
}
