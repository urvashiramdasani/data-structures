#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// function to swap two elements
void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

// function to partition array
int partition(int arr[],int p,int r) {
  srand(time(NULL));
	int random = p + rand()%(r-p);
  swap(&arr[r], &arr[random]);
  int pivot = arr[r];
	int i = p-1;
	for(int j=p;j<=r-1;j++) {
		if(arr[j]<=pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[r]);
	return (i+1);
}

// function to perform quicksort
void quicksort(int arr[],int p,int r) {
	if(p>=r) return;
	int q = partition(arr,p,r);
	quicksort(arr,p,q-1);
	quicksort(arr,q+1,r);
}

int main() {
	int n;
	printf("\nEnter the number of elements in Array : ");
	scanf("%d",&n);
	int arr[n];

  // inputting the array
	printf("\nEnter the elements in array : ");
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	
  // quicksort
  quicksort(arr,0,n-1);
	
  // displaying the array
  printf("\nElements after Sorting : ");
  for(int i=0; i<n; i++) printf("%d ", arr[i]);
  return 0;
}
