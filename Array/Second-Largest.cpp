#include <iostream>

using namespace std;

int getLargest(int arr[], int n) {
    int res = 0;
    for(int i = 1; i<n; i++) {
        if(arr[i] > arr[res]) res = i;
    }
    return res;
};

int secondLargestNaive(int arr[], int n) {
    int largest = getLargest(arr, n);
    int res = -1;
    for(int i=0; i<n; i++) {
        if(arr[i] != arr[largest]) {
            if(res == -1) res = i;
            else if(arr[i] > arr[res]) res = i;
        }
    }
    return res;
};

int secondLargestEff(int arr[], int n) {
    int res = -1, largest = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] > arr[largest]) {
            res = largest;
            largest = i;
        } else if(arr[i] < arr[largest]) {
            if(res == -1 || arr[i] > arr[res]) res = i;
        }
    }
    return res;
};

int main() {
    int a1[] = {10, 20, 30, 50, 40, 60};
    int a2[] = {2, 3, 4, 1, 6, 5};
    
    // Naive Approach - theta(n)
    int i = secondLargestNaive(a1, 6);
    cout<<"Index of Second Largest Element of a1 using Naive Approach is "<<i<<"\n";
    
    // Efficient Approach
    int j = secondLargestEff(a2, 6);
    cout<<"Index of Second Largest Element of a2 using Efficient Approach is "<<j;
}
