// Maximum Subarray Problem

// Include all libraries
#include <stdio.h>

// Function to find maximum subarray that crosses the midpoint
int* find_max_crossing_subarray(int arr[], int low, int mid, int high) {
  int left_sum = -65535, sum = 0, right_sum = -65535, max_left, max_right;

  for(int i = mid; i >= low; i--) {
    sum += arr[i];
    if(sum>left_sum) {
      left_sum = sum;
      max_left = i;
    }
  }

  sum = 0;
  for(int i = mid + 1; i <= high; i++) {
    sum += arr[i];
    if(sum > right_sum) {
      right_sum = sum;
      max_right = i;
    }
  }

  static int result[3];
  result[0] = max_left;
  result[1] = max_right;
  result[2] = left_sum + right_sum;

  return result;
}

// Function to maximum subarray
int * find_maximum_subarray(int arr[], int low, int high) {
  static int result[3];
  if(high == low) {
    result[0] = low;
    result[1] = high;
    result[2] = arr[low];
    return result;
  } else {
    int mid = (low + high)/2;

    int * left = find_maximum_subarray(arr, low, mid);
    int * right = find_maximum_subarray(arr, mid + 1, high);
    int * cross = find_max_crossing_subarray(arr, low, mid, high);

    if(left[2] >= right[2] && left[2] >= cross[2]) return left;
    else if(right[2] >= left[2] && right[2] >= cross[2]) return right;
    else return cross;
  }
}

// main
int main(void) {
  int n;
  printf("\nEnter the size of array : ");
  scanf("%d", &n);

  int arr[n];
  printf("\nEnter the elements of array : ");
  for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

  int * result = find_maximum_subarray(arr, 0, n-1);
  printf("\nThe maximum subarray start from %d and ends to %d with the maximum sum %d ", result[0], result[1], result[2]);
  
  return 0;
}
