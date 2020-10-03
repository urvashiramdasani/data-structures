#include <iostream>
#include <algorithm>

using namespace std;

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
};

void moveToEndNaive(int arr[], int n) {
    for(int i=0; i<n; i++) {
        if(arr[i] == 0) {
            for(int j=i+1; j<n; j++) {
                if(arr[j] != 0) {
                    swap(&arr[j], &arr[i]);
                    break;
                }
            }
        }
    }  
};

void moveToEndEff(int arr[], int n) {
    int count = 0;
    for(int i=0; i<n; i++) {
        if(arr[i] != 0) {
            swap(&arr[i], &arr[count]);
            count++;
        }
    }
};

int main() {
    int a1[] = {10, 0, 0, 20, 0, 30};
    int a2[] = {1, 1, 1, 0, 3, 3};
    
    // Naive Approach - Time and Space O(n)
    moveToEndNaive(a1, 6);
    cout<<"a1 elements after move : ";
    for(int i=0; i<6; i++) cout<<a1[i]<<" ";
    cout<<endl;
    
    // Efficient Approach - Time O(n) and Space O(1)
    moveToEndEff(a2, 6);
    cout<<"a2 elements after move : ";
    for(int i=0; i<6; i++) cout<<a2[i]<<" ";
}
