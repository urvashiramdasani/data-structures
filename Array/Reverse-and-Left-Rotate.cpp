#include <iostream>
#include <algorithm>

using namespace std;

void reverse(int arr[], int n) {
    int low = 0, high = n-1;
    while(low < high) {
        int tmp = arr[low];
        arr[low] = arr[high];
        arr[high] = tmp;
        low++;
        high--;
    }
};

void lRotate(int arr[], int n) {
    int tmp = arr[0];
    for(int i=1; i<n; i++) arr[i-1] = arr[i];
    arr[n-1] = tmp;
};

int main() {
    int a1[] = {10, 0, 0, 20, 0, 30};
    reverse(a1, 6);
    cout<<"Array after reverse : ";
    for(int i=0; i<6; i++) cout<<a1[i]<<" ";
    
    lRotate(a1, 6);
    cout<<"\nArray after Left Rotate : ";
    for(int i=0; i<6; i++) cout<<a1[i]<<" ";
}
