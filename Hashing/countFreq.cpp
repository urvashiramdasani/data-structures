#include <iostream>
#include <unordered_map>

using namespace std;

void countFreq(int arr[], int n) {
    unordered_map < int, int > m;
    for(int i = 0; i < n; i++) 
        m[arr[i]]++;
    for(auto x : m)
        cout << x.first << " " << x.second << endl;
}

int main() {
    int arr[] = {50, 50, 10, 40, 10};
    int n = 5;
    countFreq(arr, n);
    return 0;
}