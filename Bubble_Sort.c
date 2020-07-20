#include <stdio.h>

//function to implement Bubble Sort Recursively 
void bubblesort(int arr[], int n) {

  if(n == 1) return;

  for(int i=0; i<n-1; i++) {
    if(arr[i] > arr[i+1]) {
      int tmp = arr[i];
      arr[i] = arr[i+1];
      arr[i+1] = tmp;
    }
  }

  bubblesort(arr, n-1);
}

int main(void) {
  int arr1[] = {5,6,2,4,1,3};

  // Iterative Approach
  for(int i=0; i<5; i++) { // iterating through n-1 elements
    for(int j=0; j<5-i; j++) {
      if(arr1[j] > arr1[j+1]) {
        int tmp = arr1[j]; // swapping
        arr1[j] = arr1[j+1];
        arr1[j+1] = tmp;
      }
    }
  }
  printf("Array 1 \n");
  for(int i=0; i<6; i++) printf("%d ", arr1[i]);

  int arr2[] = {9,0,2,6,4,5};
  // Recursive Approach
  bubblesort(arr2, 6);
  printf("\nArray 2 \n");
  for(int i=0; i<6; i++) printf("%d ", arr2[i]);
  return 0;
}
