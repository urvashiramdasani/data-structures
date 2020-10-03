#include <iostream>

using namespace std;

int removeDuplicateNaive(int arr[], int n) {
    int tmp[n];
    tmp[0] = arr[0];
    int res = 1;
    for(int i=0; i<n; i++) {
        if(tmp[res - 1] != arr[i]) {
            tmp[res] = arr[i];
            res++;
        }
    }
    for(int i=0; i<n; i++) arr[i] = tmp[i];
    return res;
};

int removeDuplicateEff(int arr[], int n) {
    int res = 1;
    for(int i=1; i<n; i++) {
        if(arr[res - 1] != arr[i]) {
            arr[res] = arr[i];
            res++;
        }
    }
    return res;
};

int main() {
    int a1[] = {10, 10, 10, 20, 20, 30};
    int a2[] = {1, 1, 1, 2, 3, 3};
    
    // Naive Approach - Time and Space O(n)
    int res = removeDuplicateNaive(a1, 6);
    cout<<"Size of a1 after removing duplicates is "<<res<<endl;
    
    // Efficient Approach - Time O(n) and Space O(1)
    res = removeDuplicateEff(a2, 6);
    cout<<"Size of a2 after removing duplicates is "<<res<<endl;
}
