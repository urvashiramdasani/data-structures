#include <iostream>
#include <unordered_set>

using namespace std;

// Efficient implementation
int countDistinct(int arr[], int n) {
    unordered_set < int > s;
    for(int i = 0; i < n; i++) 
        s.insert(arr[i]);
    return s.size();
}

// Improved Efficient implementation
int CountDistinct(int arr[], int n) {
    unordered_set < int > s(arr, arr + n);   // Good point
    return s.size(); 
}

int main() {
    int arr[] = {10, 20, 10, 20, 30};
    int n = 5;
    cout << "Number of distinct elements : " << countDistinct(arr, n);
    cout << "\nNumber of distinct elements : " << CountDistinct(arr, n);
    return 0;
}