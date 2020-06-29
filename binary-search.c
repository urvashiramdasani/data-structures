// Program to implement binary search on a set of integers

#include<stdio.h>

int binary_search(int arr[], int val, int size) {
    int lb = 0;
    int ub = size-1;
    while(lb<=ub) {
        int mid = (lb+ub)/2;
        if(arr[mid]==val) {
            printf("%d found at position %d",val,mid+1);
            return 1;
        }
        else if(val>mid) lb=mid+1;
        else ub=mid-1;
    }
    return -1;
}
void sort(int arr[],int size) {
    for(int i=0;i<size;i++) {
        int d=i;
        while(d>0 && arr[d]<arr[d-1]) {
            int temp = arr[d];
            arr[d] = arr[d-1];
            arr[d-1] = temp;
            d--;
        }
    }
}
void main() {
    int size,val;
    printf("\nEnter the size of array : ");
    scanf("%d",&size);
    int arr[size];
    printf("\nEnter elements in array : ");
    for(int i=0;i<size;i++) {
        scanf("%d",&arr[i]);
    }
    printf("\nEnter the value you want to search : ");
    scanf("%d",&val);
    sort(arr,size);
    int test = binary_search(arr,val,size);
    if(test==1) printf("\nSearch Successful!");
    else if(test==-1) printf("\nElement Not Found!");
}
