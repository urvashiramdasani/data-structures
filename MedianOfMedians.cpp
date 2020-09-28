#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int median(int arr[], int n) {
	sort(arr, arr+n);
	return arr[n/2];
};

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
};

int partition(int arr[], int low, int high, int medofmed) {
	int i;
	for(i = low; i < high; i++) {
		if(arr[i] == medofmed) break;
	}
	swap(&arr[i], &arr[high]);

	i = low;
	for(int j = low; j <= high - 1; j++) {
		if(arr[j] <= medofmed) {
			swap(&arr[i], &arr[j]);
			i++;
		}
	}
	swap(&arr[i], &arr[high]);
	return i;
};

int MedianOfMedians(int arr[], int low, int high, int k) {
	if(k > 0 && k <= high - low + 1) {
		int n = high - low + 1;
		int i, med[(n+4)/5];

		for(i = 0; i < n / 5; i++) med[i] = median(arr + low + i * 5, 5);
		if(i * 5 < n) {
			med[i] = median(arr + low + i * 5, n % 5);
			i++;
		}

		int medofmed;
		if(i == 1) medofmed = med[i-1]; // for less than 5 elements
		else MedianOfMedians(med, 0, i - 1, i / 2);

		int pos = partition(arr, low, high, medofmed);
		if(pos - low == k - 1) return arr[pos];
		if(pos - low > k - 1) return MedianOfMedians(arr, low, pos - 1, k);
		
		return MedianOfMedians(arr, pos + 1, high, k - pos + low - 1);
	}
	return -1;
};

int main() {
	cout<<"Enter the size of array : ";
	int n; cin>>n;
  	int arr[n];
  
  	cout<<"\nEnter the elements in array : ";
	for(int i=0; i<n; i++) cin>>arr[i];
  
  	cout<<"\nEnter the value of k : ";
  	int k; cin>>k;

  	int k_smallest = MedianOfMedians(arr, 0, n - 1, k);
	if(k_smallest == -1) cout<<"k i.e, "<<k<<" is greater than the number of elements i.e, "<<n;
  	else cout<<"The kth smallest element is : "<<k_smallest;
  	return 0;
}
