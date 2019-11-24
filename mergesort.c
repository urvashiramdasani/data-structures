#include<stdio.h>

void merge(int arr[],int l,int m,int r) {
	int n1 = m-l+1;
	int n2 = r-m;
	int a1[n1],a2[n2];
	for(int i=0;i<n1;i++) {
		a1[i] = arr[l+i];
	}
	for(int i=0;i<n2;i++) {
		a2[i] = arr[m+1+i];
	}
	int i=0;
	int j=0;
	int k=l;
	while(i<n1 && j<n2) {
		if(a1[i]<=a2[j]) {
			arr[k] = a1[i];
			i++;
		}
		else {
			arr[k] = a2[j];
			j++;
		}
		k++;
	}
	while(i<n1) {
		arr[k] = a1[i];
		k++;
		i++;
	}
	while(j<n2) {
		arr[k] = a2[j];
		k++;
		j++;
	}
}

void mergesort(int arr[],int l,int r) {
	if(r>l) {
		int mid = (l+r)/2;
		mergesort(arr,l,mid);
		mergesort(arr,mid+1,r);
		merge(arr,l,mid,r);
	}
}

void main() {
	int size;
	printf("\nEnter the size of array : ");
	scanf("%d",&size);
	int arr[size];
	printf("\nEnter elements in array : ");
	for(int i=0;i<size;i++) {
		scanf("%d",&arr[i]);
	}
	mergesort(arr,0,size-1);
	printf("\nSorted array is ");
	for(int i=0;i<size;i++) {
		printf("%d ",arr[i]);
	}
}