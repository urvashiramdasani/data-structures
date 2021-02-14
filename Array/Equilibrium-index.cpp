// Problem : Equilibrium index of an array.
// Equilibrium index of an array is an index such that the sum of elements 
// at lower indexes is equal to the sum of elements at higher indexes.

#include <iostream>
#include <numeric>  // For accumulate

using namespace std;

int main() {
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    
    // Find sum
    int sum = 0,leftsum = 0;
    accumulate(a, a + n, sum);
    
    // Find equilibriam index
    for(int i = 0; i < n; i++) {
        sum -= a[i];
        if(sum == leftsum) {
            cout << "Equilibrium index : " << i;
            break;
        }
        leftsum += a[i];
    }
}
