#include <stdio.h>

// function to swap two numbers
void swap(int *num1, int *num2) {
  int tmp = *num1;
  *num1 = *num2;
  *num2 = tmp;
}

int main(void) {
  
  // inputting the size of array
  printf("Enter the number of elements in array : ");
  int n; scanf("%d", &n);
  int arr[n];

  // inputting the array
  printf("\nEnter the elements in array: ");
  for(int i=0; i<n; i++) scanf("%d", &arr[i]);

  
  return 0;
}
