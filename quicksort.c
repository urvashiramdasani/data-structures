#include<stdio.h>

int partition(int arr[],int p,int r) {
	int pivot = arr[r-1];
	int i = p-1;
	for(int j=p;j<r-1;j++) {
		if(arr[j]<=pivot) {
			i++;
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	int temp = arr[i+1];
	arr[i+1] = arr[r-1];
	arr[r-1] = temp;
	return (i+1);
}

void quicksort(int arr[],int p,int r) {
	if(p>=r) return;
	int q = partition(arr,p,r);
	quicksort(arr,p,q-1);
	quicksort(arr,q+1,r);
}

void display(int arr[],int size) {
	printf("\nSorted Array is ");
	for(int i=0;i<size;i++) {
		printf("%d ",arr[i]);
	}
}

void main() {
	int size;
	printf("\nEnter the size of array : ");
	scanf("%d",&size);
	int arr[size];
	printf("\nEnter the elements in array : ");
	for(int i=0;i<size;i++) {
		scanf("%d",&arr[i]);
	}
	quicksort(arr,0,size);
	display(arr,size);
}