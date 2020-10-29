// Binary heap is used in heap sort and implementation of priority queue
// Binary heap is a complete binary tree (from left to right)
// We want to store elements in array, hence we store from left to right to not waste any space in array and to maintain parent-child relstionship.
// left(i) = 2 * i + 1, right(i) = 2 * i + 2, parent = floor((i - 1) / 2)
// Advantages - elements are at contiguous locations, cache friendly, locality of reference, no extra space needed to store pointers
// The indices increase level by level from left to right
// Height of binary tree is log(size). Insert takes O(log(size)) time
// minHeapify is O(h). h = log(n), n is the number of elements. Auxiliary space is also O(h)
// Decrease Key, Delete is O(h)
// Build heap takes O(n), see derivation on GFG.
// Maximum number of nodes at height h = ceil(n / 2 ^ (h + 1))
// Complete below program

#include <iostream>
#include <climits>

using namespace std;
// use example to verify working in future

class MinHeap {
    int arr[], size, capacity;
    MinHeap(int c) {
        arr = new int[c];
        size = 0;
        capacity = c;
    }
    int left(int i) return 2 * i + 1;
    int right(int i) return 2 * i + 2;
    int parent(int i) return (i - 1) / 2;
    
    void insert(int x) {
        if(size == capacity) return;
        size++;
        arr[size - 1] = x;
        for(int i = size - 1; i != 0 && arr[parent(i)] > arr[i]) {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }
    
    void minHeapify(int i) {
        int lt = left(i), rt = right(i), smallest = i;
        if(lt < size && arr[lt] < arr[i]) smallest = lt;
        if(rt < size && arr[rt] < arr[smallest]) smallest = rt;
        if(smallest != i) {
            swap(arr[i], arr[smallest]);
            minHeapify(smallest);
        }
    }
    
    int extractMin() {
        if(size == 0) return INT_MAX;
        if(size == 1) {
            size--;
            return arr[0];
        }
        swap(arr[0], arr[size - 1]);
        size--;
        minHeapify(0);
        return arr[size];
    }
    
    void decreaseKey(int i, int x) {
        arr[i] = x;
        while(i != 0 && arr[parent] > arr[i]) {
            swap(arr[i], arr[parent]);
            i = parent(i);
        }
    }
    
    void deleteNode(int i) {
        decreaseKey(i, -INT_MAX);
        int min = extractMin();
    }
    
    void buildheap() {
        for(int i = (size - 2) / 2; i >= 0; i--) minHeapify(i); // size - 2 by 2 - use parent formula for leaf nodes.
    }
}

int main() {
    
}
