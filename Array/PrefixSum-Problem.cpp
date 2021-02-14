// Problem : Consider an array of size N with all initial values as 0. 
// Perform given 'm' add operations from index 'a' to 'b' and evaluate highest 
//element in array. An add operation adds 100 to all elements from index a to b 
// (both inclusive).

// Solution : We will use PrefixSum concept to solve this problem in linear time.

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n; cin>>n;
    int arr[n] = {0};
    int m; cin>>m;
    
    for(int i = 0; i < m; i++) {
        int a, b; cin>>a>>b;
        arr[a - 1] += 100;
        arr[b] -= 100;
    }
    
    // PrefixSum Concept
    for(int i = 1; i < n; i++) arr[i] += arr[i - 1];
    for(int i = 0; i < n; i++) cout<<arr[i]<<" ";
    
    cout<<"\nMaximum element : "<<int(*max_element(arr, arr + n));
}

/* Input :                     Output : 
5                               200 300 200 100 0
3                               Maximum element : 300
2 4
1 3
1 2
*/ 
