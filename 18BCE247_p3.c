#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 = r - m; 
    int L[n1], R[n2]; 

    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1 + j]; 
  
    i = 0;  
    j = 0;  
    k = l;  
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) { 
        int m = l + (r - l) / 2; 
        mergeSort(arr, l, m); 
        mergeSort(arr, m + 1, r); 
  
        merge(arr, l, m, r); 
    } 
}

void Write(int arr[], int n) {
  FILE * f;
  f = fopen("sorted_file.txt", "w");
  for(int i=0;i<n;i++) fprintf(f, "%d ", arr[i]);
  fclose(f);
}

int main(void) {
  // opening the data file
  FILE * fp, * f;
  fp = fopen("data.txt", "r");

  // Checking for Error
  if(fp == NULL || f == NULL) {
    perror("Error in opening file\n");
    exit(EXIT_FAILURE);
  }

  // Reading from file
  char ch;
  int count = -1, arr[500], k = 0;
  while((ch = fgetc(fp)) != EOF) {
    if(count % 49 == 0 && count != 0) {
      // mergeSort(arr, 0, 49);

      if(k == 0) {
        mergeSort(arr, 0, 49);
        printf("\n\nSorting 0 to 50 : ");
        for(int i=0;i<50;i++) printf("%d ", arr[i]);
        Write(arr, 50);
        k = 1;
      } else {
        f = fopen("sorted_file.txt", "r");
        while((ch = fgetc(f)) != EOF) {
          count++;
          fscanf(f, "%d", &arr[count]);
        }
        mergeSort(arr, 0, count-1);
        printf("\n\nSorting 0 to %d : ", count);
        for(int i=0;i<count;i++) printf("%d ", arr[i]);
        Write(arr, count);
      }
      count = 0;
    } else {
      count++; 
      fscanf(fp, "%d", &arr[count]);
    }
  }
  
  return 0;
}