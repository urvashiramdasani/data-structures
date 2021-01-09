// This program finds the maximum sum of k consecutive elements in O(n) time.
#include <iostream>

using namespace std;

int windowSliding(int a[], int n, int k) {
    if(k > n) return -1;
    int curr_sum = 0, max_sum = 0;
    for(int i = 0; i < k; i++) curr_sum += a[i];
    max_sum = curr_sum;
    for(int i = 1; i < n - k + 1; i++) {
        curr_sum -= a[i - 1];
        curr_sum += a[i + k - 1];
        if(curr_sum > max_sum) max_sum = curr_sum;
    }
    return max_sum;
}

int main() {
    int n, k;
    cout<<"\nEnter the size of the array : "; cin>>n; 
    int a[n];
    cout<<"\nEnter the elements in array : ";
    for(int i = 0; i < n; i++) cin>>a[i];
    cout<<"\nEnter the value of k : "; cin>>k;
    int max_sum = windowSliding(a, n, k);
    if(max_sum == -1) cout<<"Error : "<<k<<" is greater than "<<n;
    else cout<<"Maximum sum of "<<k<<" consecutive elements in the array is : "<<max_sum;
}
